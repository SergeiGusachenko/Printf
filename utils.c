/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgusache <sgusache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 15:22:39 by sgusache          #+#    #+#             */
/*   Updated: 2019/06/21 00:16:43 by sgusache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"

void	fill(t_printf **f, char *str, int start, int end)
{
	while (start != end)
	{
		str[start] = (*f)->filling_c;
		start++;
	}
	str[end] = '\0';
}

void	get_res_u(t_printf **f, va_list ap, unsigned long long int *res)
{
	if ((*f)->lenght_result == 1)
	{
		if ((*f)->spec == 'o' || (*f)->spec == 'O')
			(*res) = (unsigned char)va_arg(ap, unsigned int);
		else
			(*res) = (unsigned char)va_arg(ap, unsigned int);
	}
	else if ((*f)->lenght_result == 2 || (*f)->spec == 'U')
	{
		if ((*f)->spec == 'U')
			(*res) = va_arg(ap, unsigned long int);
		else
			(*res) = (unsigned short)va_arg(ap, int);
	}
	else if ((*f)->lenght_result == 3)
		(*res) = va_arg(ap, long int);
	else if ((*f)->lenght_result == 4)
	{
		(*res) = ((*f)->spec == 'd' || (*f)->spec == 'i') ?
		va_arg(ap, long long int) : va_arg(ap, unsigned long long int);
	}
	else
		get_res_u_c(f, ap, res);
}

void	get_res_u_c(t_printf **f, va_list ap, unsigned long long int *res)
{
	if ((*f)->lenght_result == 5)
		(*res) = va_arg(ap, intmax_t);
	else if ((*f)->lenght_result == 6)
		(*res) = va_arg(ap, size_t);
	else if ((*f)->lenght_result == 7)
		(*res) = va_arg(ap, int);
	else if ((*f)->lenght_result == 8)
		(*res) = va_arg(ap, int);
	else if ((*f)->lenght_result == NOT_EXIST)
	{
		if ((*f)->spec == 'O')
			(*res) = va_arg(ap, unsigned long long);
		else
			(*res) = (unsigned int)va_arg(ap, int);
	}
}

char	*ft_itoa_base_u(unsigned long long int n, int base, int uppercase)
{
	char	*str;
	int		i;
	int		length;

	if (base < 2 || base > 16)
		return (NULL);
	if (base == 10)
		return (ft_itoa_u(n));
	if (n == 0)
		return ("0\0");
	length = ft_nbrlen_u(n, base);
	str = (char*)malloc(sizeof(*str) * (length + 1));
	i = 0;
	while (i < length)
	{
		if (base > 10 && (n % base >= 10) && uppercase)
			str[i++] = (n % base) - 10 + 'A';
		else if (base > 10 && (n % base >= 10))
			str[i++] = (n % base) - 10 + 'a';
		else
			str[i++] = (n % base) + '0';
		n /= base;
	}
	str[i] = '\0';
	return (ft_strrev_u(str));
}

int		nb_size_u(unsigned long long int nb)
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
