/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgusache <sgusache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 19:05:13 by sgusache          #+#    #+#             */
/*   Updated: 2019/05/28 22:31:17 by sgusache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_countint(char *str)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) && str[i] != '0')
			count++;
		i++;
	}
	return (count);
}

int				ft_atoi(const char *str)
{
	int		i;
	int		is_neg;
	int		number;

	i = 0;
	is_neg = 0;
	number = 0;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n')
		|| (str[i] == '\v') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	if (ft_countint((char*)&str[i]) > 11)
		return ((str[0] == '-') ? 0 : -1);
	if (str[i] == '-')
		is_neg = 1;
	if ((str[i] == '-') || (str[i] == '+'))
		i++;
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		number *= 10;
		number += ((int)str[i] - '0');
		i++;
	}
	return ((is_neg) ? (-number) : (number));
}
