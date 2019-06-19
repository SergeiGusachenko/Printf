/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgusache <sgusache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 13:17:39 by sgusache          #+#    #+#             */
/*   Updated: 2019/06/19 13:54:24 by sgusache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"

void	parse(t_printf **factor, int *i, va_list ap)
{
	int result;
	(*i)++;
	result = 0;
	while((ft_strchr(" #0-+\0",(*factor)->format[*i]) != NULL) && (*factor)->format[*i] != '\0')
		check_flags(factor, i);
	check_width(factor, i, ap);
	if((*factor)->format[*i] == '.' || (*factor)->format[*i] == '*'
	|| ft_isdigit((*factor)->format[*i]))
	{
		if((*factor)->format[*i] == '*' || ft_isdigit((*factor)->format[*i]))
			check_width(factor, i, ap);
		else
		{
			(*i)++;
			check_precision(factor, i, ap);
		}
	}
	check_lenght(factor, i);
	check_specifier(factor, i);
	resolve(factor ,ap);
}
