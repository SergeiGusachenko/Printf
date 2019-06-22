/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hendlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgusache <sgusache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 18:38:17 by sgusache          #+#    #+#             */
/*   Updated: 2019/06/21 00:54:05 by sgusache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"

char	*ft_update(char *str, char *update)
{
	if (str != NULL && str[0] != '0')
		free(str);
	str = update;
	return (str);
}

int		nb_uns_size(unsigned long long int nb)
{
	int		size;

	size = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb = nb / 10;
		size++;
	}
	return (size);
}

char	*ft_long_itoa(unsigned long long int res)
{
	char	*str;
	int		i;
	int		size;

	size = nb_uns_size(res);
	i = 0;
	str = (char*)malloc(sizeof(char) * size + 1);
	str = fill_str(str, res, i);
	str_rev(str, i);
	return (str);
}

char	*s_r_m(t_printf **factor, char *s_r, long long int res)
{
	s_r = (res < 0 && (*factor)->lenght_result != 4 &&
	(*factor)->lenght_result != 5 && res > LONG_MIN) ?
	ft_update(s_r, ft_strjoin("-", s_r)) : s_r;
	s_r = (res >= 0 && (*factor)->flag_p > 0) ?
	ft_update(s_r, ft_strjoin("+", s_r)) : s_r;
	s_r = ((*factor)->flag_s > 0 && (*factor)->flag_p == 0 && res > 0) ?
	ft_update(s_r, ft_strjoin(" ", s_r)) : s_r;
	return (s_r);
}

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
		(*res) = ((*f)->spec == 'd' || (*f)->spec == 'i') ?
		va_arg(ap, long long int) : va_arg(ap, unsigned long long int);
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
		(*res) = ((*f)->spec == 'D') ? va_arg(ap, long int) : va_arg(ap, int);
}
