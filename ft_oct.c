/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_oct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgusache <sgusache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 02:19:20 by sgusache          #+#    #+#             */
/*   Updated: 2019/06/20 23:53:42 by sgusache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"

int		get_w_size(t_printf **f, int res_size)
{
	int w_size;

	w_size = 0;
	w_size = (*f)->width - res_size;
	if ((*f)->precision > res_size)
		w_size = (*f)->width - (*f)->precision;
	w_size = ((*f)->flag_h > 0) ? w_size - 1 : w_size;
	return (w_size);
}

void	flg_z_m(t_printf **f, char **pr, char **w, char **res)
{
	char *tmp;

	tmp = NULL;
	if ((*f)->flag_z > 0)
	{
		if ((*pr) != NULL)
		{
			(*pr) = ft_update((*pr), ft_strjoin(*pr, (*w)));
			return ;
		}
		if ((*f)->flag_h > 0)
		{
			*res = ft_update(*res, ft_strjoin("0", *res));
			*res = ft_update(*res, ft_strjoin(*res, (*w)));
			return ;
		}
	}
	tmp = ft_strdup(*w);
	*res = (*w != NULL && (*f)->flag_m > 0) ?
	ft_update((*w), ft_strjoin((*res), tmp)) :
	ft_update((*w), ft_strjoin(tmp, *res));
	(*w) = ft_strdup(tmp);
	free(tmp);
}

void	init_w_pr(t_printf **f, char **pr, char **w, char **res)
{
	int		w_size;

	w_size = get_w_size(f, ft_strlen(*res));
	if ((*f)->precision > (int)ft_strlen(*res))
	{
		(*pr) = (char*)ft_memalloc(sizeof(char)
		* ((*f)->precision - ft_strlen(*res) + 1));
		(*f)->filling_c = '0';
		fill(f, (*pr), 0, (*f)->precision - ft_strlen(*res));
		(*res) = ft_update((*pr), ft_strjoin(*pr, *res));
		if (w_size < 0)
			return ;
	}
	*res = ((*f)->flag_h > 0 && (*f)->flag_z == 0) ?
	ft_update(*res, ft_strjoin("0", *res)) : *res;
	if (w_size > 0)
	{
		(*w) = (char*)ft_memalloc(sizeof(char) * (w_size + 1));
		(*f)->filling_c = ' ';
		if (((*f)->flag_z > 0) && ((*f)->precision <= 0) && (*f)->flag_m == 0)
			(*f)->filling_c = '0';
		fill(f, (*w), 0, w_size);
		flg_z_m(f, pr, w, res);
	}
}

void	init_s(t_printf **f, va_list ap,
unsigned long long int *res, char **str)
{
	*res = 0;
	*str = NULL;
	get_res_u(f, ap, res);
	*str = (*res > 0) ? ft_itoa_base_u(*res, 8, 0) : NULL;
}

char	*ft_oct(t_printf **factor, va_list ap)
{
	unsigned long long int	res;
	char					*str;
	char					*pr;
	char					*w;

	pr = NULL;
	w = NULL;
	init_s(factor, ap, &res, &str);
	init_w_pr(factor, &pr, &w, &str);
	if (res == 0 && w != NULL && w)
	{
		(*factor)->resul_s = ft_strdup(w);
		free(w);
		return ((*factor)->resul_s);
	}
	if (res == 0)
	{
		if (w == NULL && ((*factor)->flag_h > 0 || (*factor)->precision == -1))
			return ("0");
		str = ((*factor)->flag_m > 0) ? ft_strjoin(str, w) : ft_strjoin(w, str);
	}
	(*factor)->resul_s = (str != NULL) ? ft_strdup(str) : ft_strnew(1);
	if (str != NULL && str[0] != '0')
		free(str);
	return ((*factor)->resul_s);
}
