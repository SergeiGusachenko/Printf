/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgusache <sgusache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 00:52:54 by sgusache          #+#    #+#             */
/*   Updated: 2019/06/19 14:20:20 by sgusache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"

void	get_result(t_printf **f, va_list ap, long long int *res)
{
	if ((*f)->lenght_result == 1)
		(*res) = (char)va_arg(ap, int);
	else if ((*f)->lenght_result == 2)
		(*res) = (short)va_arg(ap, int);
	else if ((*f)->lenght_result == 3)
		(*res) = va_arg(ap, long int);
	else if ((*f)->lenght_result == 4)
	{
		if ((*f)->spec == 'd' || (*f)->spec == 'i')
			(*res) = va_arg(ap, long long int);
		else
			(*res) = va_arg(ap, unsigned long long int);
	}
	else if ((*f)->lenght_result == 5)
		(*res) = va_arg(ap, intmax_t);
	else if ((*f)->lenght_result == 6)
		(*res) = va_arg(ap, unsigned long int);
	else if ((*f)->lenght_result == 7)
		(*res) = va_arg(ap, int);
	else if ((*f)->lenght_result == 8)
		(*res) = va_arg(ap, int);
	else if ((*f)->lenght_result == NOT_EXIST)
	{
		if ((*f)->spec == 'D')
			(*res) = va_arg(ap,long int);
		else
			(*res) = va_arg(ap, int);
	}
}

char	*in_pr(t_printf **f, char **pr, long long int res, char **r)
{
	int		p_s;

	(*r) = (res >= 0) ? ft_itoa(res) : ft_itoa(-res);
	p_s = (*f)->precision - nb_size(res);
	if (p_s > 0)
	{
		(*pr) = (char*)ft_memalloc(sizeof(char) * p_s + 1); //leak
		(*f)->filling_c = '0';
		fill(f, (*pr), 0, p_s);
		if (res < 0)
		{
			(*pr) = ft_update((*pr), ft_strjoin((*pr), (*r)));
			return (*r) = ft_update((*pr), ft_strjoin("-", (*pr)));
		}
		(*pr) = (res > 0 && (*f)->flag_p > 0) ?
		ft_update((*pr), ft_strjoin("+", (*pr))) : (*pr);
		(*r) = ft_update(*r, ft_strjoin(*pr, *r));
		free(*pr);
		return (NULL); //leak
	}
	return (*r);
}

void	in_w(t_printf **f, char **w, char **r, long long int res)
{
	int w_s;
	int r_s;
	int r_size;
	char	*s;

	s = NULL;
	r_size = nb_size(res);
	r_s = ft_strlen(*r);
	w_s = (*f)->width - r_s;
	w_s = (res < 0 && (r_s == r_size)) ? (*f)->width - r_s - 1 : (*f)->width - r_s;
	(*f)->filling_c = ((*f)->flag_z > 0 && (w_s - r_s >= 0) && (*f)->flag_m == 0) ? '0' : ' ';
	if ((*f)->flag_result > 0)
		w_s = (((*f)->filling_c == ' ' && ((res < 0) || (res > 0 && (*f)->flag_p > 0 && (r_s - 2*(*f)->precision > 0))))) ? (*f)->width - r_s - 1 : (*f)->width - r_s;
	if (w_s > 0)
	{
		(*w) = (char*)ft_memalloc(sizeof(char) * (w_s + 1));
		fill(f, (*w), 0, w_s);
		(*r) = (res < 0 && (*f)->filling_c != '0' && (r_s == r_size)) ?
		ft_update(*r, ft_strjoin("-", *r)) : *r;
		(*r) = (res > 0 && (*f)->flag_p > 0 && (*f)->filling_c != '0' && (r_s > 2*(*f)->precision > 0)) ? ft_update(*r, ft_strjoin("+", *r)) : *r;
		*w[0] = ((*f)->filling_c == '0' && (*f)->flag_s > 0) ? ' ' : *w[0];
		*w[0] = ((*f)->filling_c == '0' &&
		(*f)->flag_p > 0 && res >= 0) ? '+' : *w[0];
		*w[0] = (res < 0 && (*f)->filling_c == '0') ? '-' : *w[0];
		s = ft_strdup(*r);
		free(*r);
		(*r) = ((*f)->flag_m > 0) ? ft_update(*w, ft_strjoin(s, *w)) : ft_update(*w, ft_strjoin(*w, s)); //leak
		free(s);
	}
}

char	*ft_int(t_printf **factor, va_list ap)
{
	char			*w;
	char			*pr;
	char			*s_r;
	long long int	res;

	get_result(factor, ap, &res);
	s_r = NULL;
	w = NULL;
	pr = NULL;
	if ((*factor)->precision == 0 && res == 0)
	{
		s_r = ft_strnew(1);
		in_w(factor, &w, &s_r, res);
		return (s_r);
	}
	in_pr(factor, &pr, res, &s_r);
	in_w(factor, &w, &s_r, res);
	if (w == NULL && pr == NULL)
	{
		s_r = (res < 0 && (*factor)->lenght_result != 4 &&
		(*factor)->lenght_result != 5 && res > LONG_MIN) ?
		ft_update(s_r, ft_strjoin("-", s_r)) : s_r;
		s_r = (res >= 0 && (*factor)->flag_p > 0) ?
		ft_update(s_r, ft_strjoin("+", s_r)) : s_r;
		s_r = ((*factor)->flag_s > 0 && (*factor)->flag_p == 0 && res > 0) ?
		ft_update(s_r, ft_strjoin(" ", s_r)) : s_r;
	}
	(*factor)->resul_s = ft_strdup(s_r);
	free(s_r);
	return ((*factor)->resul_s);
}
