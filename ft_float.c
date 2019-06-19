/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgusache <sgusache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 17:55:16 by sgusache          #+#    #+#             */
/*   Updated: 2019/06/19 13:58:15 by sgusache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"

char	*get_str(t_printf **f, long long int res, int exp_size)
{
	char	*str;
	int		size;
	int		i;

	i = 0;
	size = nb_size(res) + 1;
	str = ft_memalloc(sizeof(char) * (size + 1));
	if (res < 0)
		res = -res;
	exp_size = nb_size(res) - exp_size;
	while (res != 0)
	{
		if (i == exp_size && (*f)->precision != 0)
			str[i] = '.';
		else
		{
			str[i] = ('0' + res % 10);
			res = res / 10;
		}
		i++;
	}
	str_rev(str, 0);
	return (str);
}

char	*to_str(t_printf **f, long double nb)
{
	int				exp_size;
	long long int	res;
	int				i;
	char			*str;

	i = 0;
	res = 0;
	if ((*f)->precision == 0 && ((long long int)(nb * 10) % 10) >= 5)
		nb++;
	exp_size = nb_size((long long int)nb);
	i = (*f)->precision;
	while (i != 0)
	{
		nb *= 10;
		i--;
	}
	i = 0;
	res = (long long int)nb;
	i = res % 10;
	if (ft_abs(i) >= 6)
		(res > 0) ? res++ : res--;
	str = get_str(f, res, exp_size);
	return ((res >= 0) ? str : ft_update(str, ft_strjoin("-", str)));
}

void	w_manage(t_printf **f, char **s_r, char **w, long double res)
{
	int w_size;

	w_size = (*f)->width - ft_strlen(*s_r);
	w_size = (((*f)->flag_m > 0 || res < 0) && (((*f)->flag_p > 0 && res > 0) || ((*f)->flag_s > 0))) ? w_size - 1 : w_size;
	if (w_size <= 0)
		return ;
	(*w) = (char*)ft_memalloc(sizeof(char) * w_size + 1);
	(*f)->filling_c = ((*f)->flag_m == 0 && (*f)->flag_z > 0) ? '0' : ' ';
	fill(f, *w, 0, w_size);
	if ((*f)->flag_m > 0)
	{
		*s_r = ((*f)->flag_p > 0 && res > 0) ?
		ft_update(*s_r, ft_strjoin("+", *s_r)) : *s_r;
		*s_r = (res < 0) ? ft_update(*s_r, ft_strjoin("-", *s_r)) : *s_r;
		*s_r = ((*f)->flag_p == 0 && (*f)->flag_s > 0 && res > 0) ?
		ft_update(*s_r, ft_strjoin(" ", *s_r)) : *s_r;
		*s_r = ft_update(*s_r, ft_strjoin(*s_r, *w));
		return ;
	}
	*w[0] = ((*f)->flag_s > 0 && (*f)->filling_c == '0') ? ' ' : *w[0];
	*w[0] = ((*f)->flag_p > 0 && (*f)->filling_c == '0' && res > 0) ? '+' : *w[0];
	*w[0] = ((*f)->filling_c == '0' && res < 0) ? '-' : *w[0];
	*w[0] = ((*f)->flag_p > 0 && (*f)->filling_c == '0' && res > 0) ? '+' : *w[0];
	*s_r = (res < 0) ? (ft_update(*s_r, ft_strjoin("-", *s_r))) : *s_r;
	*s_r = (res > 0 && (*f)->flag_p > 0) ? (ft_update(*s_r, ft_strjoin("+", *s_r))) : *s_r;
	*s_r = ft_update(*w, ft_strjoin(*w, *s_r));
}

char	*ft_float(t_printf **factor, va_list ap)
{
	long double		res;
	char			*str_res;
	char			*w;

	str_res = NULL;
	w = NULL;
	if ((*factor)->lenght_result == 8)
		res = va_arg(ap, long double);
	else
		res = va_arg(ap, double);
	if ((*factor)->precision == NOT_EXIST)
		(*factor)->precision = 6;
	str_res = to_str(factor, res);
	if ((*factor)->width > (int)ft_strlen(str_res))
		w_manage(factor, &str_res, &w, res);
	return (str_res);
}

