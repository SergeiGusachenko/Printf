/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgusache <sgusache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 23:51:11 by sgusache          #+#    #+#             */
/*   Updated: 2019/06/19 20:51:16 by sgusache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"

int		ft_printf(const char *restrict format, ...)
{
	int			i;
	t_printf	*factor;
	va_list		ap;
	int			ret;

	ret = 0;
	i = 0;
	factor = malloc(sizeof(t_printf));
	va_start(ap, format);
	init(&factor, format);
	while (format[i])
	{
		if (format[i] == '%')
			parse(&factor, &i, ap);
		else if (format[i])
			if (format[i] != '%')
			{
				ft_putchar(format[i]);
				(factor)->return_value++;
			}
		i++;
	}
	va_end(ap);
	ret = (factor)->return_value;
	free(factor);
	return (ret);
}
