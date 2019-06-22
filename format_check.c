/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgusache <sgusache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 15:04:32 by sgusache          #+#    #+#             */
/*   Updated: 2019/06/20 15:32:55 by sgusache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"

int		check_width(t_printf **factor, int *i, va_list ap)
{
	if ((*factor)->format[*i] == '0')
	{
		(*factor)->width = NOT_EXIST;
		return ((*i)++);
	}
	if ((*factor)->format[*i] == '*')
	{
		(*factor)->width = va_arg(ap, int);
		(*factor)->filling_c = ' ';
		if ((*factor)->width < 0)
		{
			(*factor)->width = -(*factor)->width;
			(*factor)->flag_m++;
		}
		return ((*i)++);
	}
	else if (ft_isdigit((*factor)->format[*i]))
		(*factor)->width = ft_atoi(&((*factor)->format[*i]));
	else
		(*factor)->width = NOT_EXIST;
	if ((*factor)->width != NOT_EXIST && (*factor)->format[*i] != '*')
		(*i) += nb_size((*factor)->width);
	else if ((*factor)->width == 0 && (*factor)->flag_z > 0)
		(*i)--;
	return (1);
}

void	check_precision(t_printf **factor, int *i, va_list ap)
{
	if ((*factor)->format[*i] == '*')
	{
		(*factor)->precision = va_arg(ap, int);
		(*i)++;
		return ;
	}
	else if (ft_isdigit((*factor)->format[*i]))
	{
		(*factor)->precision = ft_atoi(&((*factor)->format[*i]));
		if ((*factor)->precision == 0)
			(*i)++;
	}
	if (!(ft_isdigit((*factor)->format[*i])) && (*factor)->precision == -1)
	{
		(*factor)->precision = 0;
		return ;
	}
	if ((*factor)->precision != NOT_EXIST
	&& (*factor)->precision != STAR && (*factor)->precision != 0)
		(*i) += nb_size((*factor)->precision);
}

void	check_lenght(t_printf **factor, int *i)
{
	if ((*factor)->format[*i] == 'h' && (*factor)->format[*i + 1] == 'h')
		(*factor)->lenght_result = 1;
	else if ((*factor)->format[*i] == 'h')
		(*factor)->lenght_result = 2;
	else if ((*factor)->format[*i] == 'l' && (*factor)->format[*i + 1] == 'l')
		(*factor)->lenght_result = 4;
	else if ((*factor)->format[*i] == 'l')
		(*factor)->lenght_result = 3;
	else if ((*factor)->format[*i] == 'j')
		(*factor)->lenght_result = 5;
	else if ((*factor)->format[*i] == 'z')
		(*factor)->lenght_result = 6;
	else if ((*factor)->format[*i] == 't')
		(*factor)->lenght_result = 7;
	else if ((*factor)->format[*i] == 'L')
		(*factor)->lenght_result = 8;
	else
		(*factor)->lenght_result = NOT_EXIST;
	if ((*factor)->lenght_result == 4 || (*factor)->lenght_result == 1)
		(*i) += 2;
	else if ((*factor)->lenght_result != NOT_EXIST)
		(*i)++;
}

void	check_flags(t_printf **factor, int *i)
{
	if ((*factor)->format[*i] == ' ')
		(*factor)->flag_s++;
	else if ((*factor)->format[*i] == '-')
		(*factor)->flag_m++;
	else if ((*factor)->format[*i] == '+')
		(*factor)->flag_p++;
	else if ((*factor)->format[*i] == '#')
		(*factor)->flag_h++;
	else if ((*factor)->format[*i] == '0')
		(*factor)->flag_z++;
	else
		(*factor)->flag_result = NOT_EXIST;
	if ((*factor)->flag_result != NOT_EXIST)
	{
		(*i)++;
		(*factor)->flag_result = (*i);
	}
}

void	check_specifier(t_printf **factor, int *i)
{
	while ((*factor)->format[*i] == ' ')
		(*i)++;
	(*factor)->spec = (*factor)->format[*i];
}
