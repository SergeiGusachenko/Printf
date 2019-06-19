/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgusache <sgusache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 19:09:07 by sgusache          #+#    #+#             */
/*   Updated: 2019/05/08 03:27:54 by sgusache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		ft_strnlen(char const *str, size_t n)
{
	size_t i;

	i = 0;
	while (i < n && str[i])
		i++;
	return (i);
}

char			*ft_strncpy(char *s1, const char *s2, size_t n)
{
	size_t size;

	size = ft_strnlen(s2, n);
	if (size != n)
		ft_memset(s1 + size, '\0', n - size);
	return (ft_memcpy(s1, s2, size));
}
