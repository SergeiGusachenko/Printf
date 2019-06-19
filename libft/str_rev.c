/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_rev.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgusache <sgusache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 11:09:13 by sgusache          #+#    #+#             */
/*   Updated: 2019/05/29 14:20:22 by sgusache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	str_rev(char *str, int i)
{
	int		size;
	char	c;

	size = ft_strlen(str);
	if (i == 1)
		size++;
	while (i < size / 2)
	{
		c = str[i];
		str[i] = str[size - i - 1];
		str[size - i - 1] = c;
		i++;
	}
}
