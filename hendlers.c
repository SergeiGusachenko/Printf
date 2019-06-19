/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hendlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgusache <sgusache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 18:38:17 by sgusache          #+#    #+#             */
/*   Updated: 2019/06/19 13:54:33 by sgusache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"

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



char		*ft_long_itoa(unsigned long long int res)
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
