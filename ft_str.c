/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgusache <sgusache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 21:50:38 by sgusache          #+#    #+#             */
/*   Updated: 2019/06/20 03:49:18 by sgusache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"

char	*manage_w(t_printf **f, char *w, char **res)
{
	int size;
	int str_size;

	str_size = 0;
	if (res)
		str_size = ft_strlen(*res);
	size = 0;
	size = (str_size == 0 || (*f)->precision == 0) ? (*f)->width : ((*f)->width - str_size);
	size = (res == NULL && (*f)->spec == 'c') ? size - 1 : size;
	if (size > 0)
		w = ft_memalloc(sizeof(char) * (size + 1));
	else
		return (*res);
	size = (*res[0] == '\0' && (*f)->spec == 'c') ? size - 1 : size;
	w[size] = '\0';
	(*f)->filling_c = (((*f)->spec == 'c') && (*f)->flag_z > 0) ? '0' : ' ';
	fill(f, w, 0, size);
	if ((*f)->flag_m > 0 && res && (*f)->precision != 0)
		return (*res = ft_update(w, ft_strjoin(*res, w)));
	if (res && (*f)->precision != 0)
		return (*res = ft_update(w, ft_strjoin(w, *res)));
	return (w);
}

void	manage_str_pr(t_printf **f, char **pr, char **res)
{
	(*pr) = ft_memalloc(sizeof(char) * ((*f)->precision + 1));
	(*pr)[(*f)->precision] = '\0';
	*res = ft_strncpy(*pr, *res, (*f)->precision);
}

char	*ft_str(t_printf **factor, va_list ap)
{
	char	*res;
	char	*pr;
	char	*wdt;
	int		flag;


	flag = 0;
	pr = NULL;
	wdt = NULL;
	(*factor)->filling_c = ' ';
	if ((ft_strchr("diouxXfSscpU%", (*factor)->spec) == NULL))
	{
		res = (char*)ft_memalloc(sizeof(char) * 2);
		res[0] = (*factor)->spec;
		flag = 1;
	}
	else
		res = (char*)va_arg(ap, char*);
	if (res == NULL)
		return ("(null)");

	if ((*factor)->precision > 0 && (*factor)->precision < (int)ft_strlen(res))
		manage_str_pr(factor, &pr, &res);
	if ((*factor)->width > (int)ft_strlen(res))
		wdt = manage_w(factor, wdt, &res);
	(*factor)->resul_s = ((*factor)->precision != 0) ? ft_strdup(res) : ft_strdup(wdt);
	if (flag)
		free(res);
	// if (wdt != NULL)
	// 	free(wdt);
	return ((*factor)->resul_s);
}
