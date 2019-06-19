/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgusache <sgusache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 22:01:52 by sgusache          #+#    #+#             */
/*   Updated: 2018/12/07 20:58:35 by sgusache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	size_t	i;
	char	*sc;

	if (!s)
		return (NULL);
	sc = ft_strdup(s);
	if (!sc)
		return ((char *)NULL);
	while (*sc == ' ' || *sc == '\n' || *sc == '\t')
		sc++;
	i = ft_strlen(sc) - 1;
	while (sc[i] == ' ' || sc[i] == '\n' || sc[i] == '\t')
		i--;
	sc[++i] = '\0';
	return (ft_strdup(sc));
}
