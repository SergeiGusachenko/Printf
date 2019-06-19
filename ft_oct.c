/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_oct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgusache <sgusache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 02:19:20 by sgusache          #+#    #+#             */
/*   Updated: 2019/06/19 14:20:27 by sgusache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"

void	init_w_pr(t_printf **f, char **pr, char **w, char	**res)
{
	int w_size;
	int res_size;

	res_size = ft_strlen(*res);
	w_size = 0;
	w_size = (*f)->width - res_size;
	if ((*f)->precision > res_size)
		w_size = (*f)->width - (*f)->precision;
	w_size = ((*f)->flag_h > 0) ? w_size - 1 : w_size;
	if ((*f)->precision > res_size)
	{
		(*pr) = (char*)ft_memalloc(sizeof(char) * ((*f)->precision - res_size + 1));
		(*f)->filling_c = '0';
		fill(f, (*pr),0 ,(*f)->precision - res_size);
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
		*res = (*w != NULL && (*f)->flag_m > 0) ?
		ft_update((*w), ft_strjoin((*res), *w)) :
		ft_update((*w), ft_strjoin((*w), *res));
	}
}

char				*ft_oct(t_printf **factor, va_list ap)
{
	unsigned long long int	res;
	char					*str;
	char					*pr;
	char					*w;

	pr = NULL;
	w = NULL;
	res = 0;
	str = NULL;
	get_res_u(factor, ap, &res);
	if (res > 0)
		str = ft_itoa_base_u(res, 8, 0);
	init_w_pr(factor, &pr, &w, &str);
	if (res == 0 && w != NULL)
		return (w);
	if (res == 0)
	{
		if (w == NULL && ((*factor)->flag_h > 0 || (*factor)->precision == -1))
			return ("0");
		str = ((*factor)->flag_m > 0) ? ft_strjoin(str, w) : ft_strjoin(w, str);
	}
	(*factor)->resul_s = str;
	if (str != NULL && str[0] != '0')
		free(str);
	return ((*factor)->resul_s);
}
