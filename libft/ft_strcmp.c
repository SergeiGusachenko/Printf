/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgusache <sgusache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 18:56:34 by sgusache          #+#    #+#             */
/*   Updated: 2018/12/06 21:17:21 by sgusache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *p1, const char *p2)
{
	const unsigned char		*s1;
	const unsigned char		*s2;
	unsigned char			c1;
	unsigned char			c2;

	s1 = (const unsigned char *)p1;
	s2 = (const unsigned char *)p2;
	c1 = (unsigned char)*s1;
	c2 = (unsigned char)*s2;
	while (c1 == c2)
	{
		c1 = (unsigned char)*s1;
		c2 = (unsigned char)*s2;
		if (c1 == '\0')
			return (c1 - c2);
		s1++;
		s2++;
	}
	return (c1 - c2);
}
