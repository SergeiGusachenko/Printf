/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgusache <sgusache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 19:37:13 by sgusache          #+#    #+#             */
/*   Updated: 2019/06/11 11:18:25 by sgusache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*fill_stru(char *str, unsigned long long int nb, int i)
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

char			*ft_itoa(long long int n)
{
	char					*str;
	int						i;
	int						size;
	unsigned long long		num;

	size = nb_size(n);
	i = 0;
	if (n < 0)
	{
		num = -n;
		i++;
		size++;
	}
	str = (char *)ft_memalloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	if (n >= 0)
		str = fill_str(str, n, i);
	else
		str = fill_stru(str, num, i);
	str_rev(str, i);
	return (str);
}
