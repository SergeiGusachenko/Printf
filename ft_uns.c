/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uns.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgusache <sgusache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 13:43:59 by sgusache          #+#    #+#             */
/*   Updated: 2019/06/19 14:28:06 by sgusache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"


void	m_pr_w(t_printf **f, char **pr, char **wd, unsigned long long res)
{
	int pr_size;
	int w_size;
	int res_size;

	pr_size = 0;
	res_size = nb_size_u(res);
	if ((*f)->precision > res_size)
		pr_size = (*f)->precision - res_size;
	w_size = (*f)->width - res_size;
	if (pr_size > 0)
		w_size = (*f)->width - (*f)->precision;
	if (pr_size > 0)
	{
		(*pr) = (char*)ft_memalloc(sizeof(char) * (pr_size + 1));
		(*f)->filling_c = '0';
		fill(f, (*pr), 0, pr_size);
		(*pr) = ft_update((*pr), ft_strjoin((*pr), ft_itoa_base_u(res, 10, 0)));
	}
	if (w_size > (*f)->precision)
	{
		(*wd) = (char*)ft_memalloc(sizeof(char) * (w_size + 1));
		(*f)->filling_c = ' ';
		if ((*f)->flag_m == 0 && (*f)->flag_z > 0 && (*f)->precision == NOT_EXIST)
			(*f)->filling_c = '0';
		fill(f, (*wd), 0, w_size);
	}
}

char	*m_res(t_printf **f, char **p, char **w, unsigned long long res)
{
	char	*res_str;

	res_str = ((*f)->precision == 0 && res == 0) ? ft_strnew(1)
	: ft_itoa_base_u(res, 10, 0);
	if ((*p) != NULL && (*w) != NULL)
	{
		if ((*f)->flag_m > 0)
			return (ft_update(*p, ft_strjoin(*p, *w)));
		else
			return (ft_update(*p, ft_strjoin(*w, *p)));
	}
	if ((*p) == NULL && (*w) != NULL)
	{
		if ((*f)->flag_m > 0)
			return ft_update (*w, ft_strjoin(res_str, *w));
		else
			return ft_update (*w, ft_strjoin(*w, res_str));
	}
	if ((*p) != NULL && (*w) == NULL)
		return (*p);
	(*p) = ft_update((*p), ft_strdup(res_str));
	//free(res_str);
	res_str = NULL;
	return (*p);
}

char	*ft_uns(t_printf **factor, va_list ap)
{
	unsigned long long int	res;
	char					*pr;
	char					*wd;
	char					*tmp;

	tmp = NULL;
	pr = NULL;
	wd = NULL;
	res = 0;
	get_res_u(factor, ap, &res);
	m_pr_w(factor, &pr, &wd, res);
	return (m_res(factor, &pr, &wd, res));
}
