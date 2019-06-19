/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgusache <sgusache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 21:53:38 by sgusache          #+#    #+#             */
/*   Updated: 2019/05/14 23:13:41 by sgusache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		get_size(char const *str)
{
	int i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
		i++;
	return (i);
}

static char		*check(char const *s1, char const *s2)
{
	char *str;

	if (!s1 || !s2 || get_size(s1) == -1 || get_size(s2) == -1)
		return (NULL);
	else
		str = (char *)malloc(sizeof(char) * get_size(s1) + get_size(s2) + 1);
	return (str);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size1;
	size_t	size;
	size_t	i;
	char	*str;

	if ((str = check(s1, s2)) == NULL)
		return ((char*)NULL);
	size1 = ft_strlen(s1);
	size = size1 + ft_strlen(s2);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		str[size1 + i] = s2[i];
		i++;
	}
	str[size1 + i] = '\0';
	return (str);
}
