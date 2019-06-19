/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgusache <sgusache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 18:03:52 by sgusache          #+#    #+#             */
/*   Updated: 2018/12/08 13:41:16 by sgusache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *s1, const char *s2)
{
	char	*src;
	char	*find;
	size_t	size;

	src = (char *)s1;
	find = (char *)s2;
	size = ft_strlen(find);
	if (size == 0)
		return (src);
	while (*src)
	{
		if (ft_strncmp(src, find, size) == 0)
			return (src);
		src++;
	}
	return ((char *)NULL);
}
