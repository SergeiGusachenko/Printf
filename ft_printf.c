/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgusache <sgusache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 23:51:11 by sgusache          #+#    #+#             */
/*   Updated: 2019/06/21 00:14:29 by sgusache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"

char	*ft_strrev_u(char *str)
{
	int		i;
	int		length;
	char	temp;

	i = 0;
	length = ft_strlen(str);
	while (i < (length / 2))
	{
		temp = str[i];
		str[i] = str[length - i - 1];
		str[length - i - 1] = temp;
		i++;
	}
	str[length] = '\0';
	return (str);
}

char	*fill_str_u(char *str, unsigned long long int nb, int i)
{
	if (i == 1)
		str[0] = '-';
	if (nb == 0)
	{
		str[i] = '0';
		i++;
	}
	while (nb != 0)
	{
		str[i] = (nb % 10) + '0';
		nb = nb / 10;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_itoa_u(unsigned long long int n)
{
	char	*str;
	int		i;
	int		size;

	size = nb_size_u(n);
	i = 0;
	str = (char*)malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	str = fill_str_u(str, n, i);
	ft_strrev_u(str);
	return (str);
}

int		ft_nbrlen_u(unsigned long long int n, int base)
{
	int size;

	size = 0;
	if (n == 0)
		return (0);
	while (n != 0)
	{
		n = n / base;
		size++;
	}
	return (size);
}

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
		else if (format[i] && format[i] != '%')
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
