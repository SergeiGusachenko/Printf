/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgusache <sgusache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 15:18:47 by sgusache          #+#    #+#             */
/*   Updated: 2019/05/21 15:24:38 by sgusache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nbrlen(long long int n, int base)
{
	int size;

	size = 0;
	if (n < 0)
		size++;
	if (n == 0)
		return (0);
	while (n != 0)
	{
		n = n / base;
		size++;
	}
	return (size);
}
