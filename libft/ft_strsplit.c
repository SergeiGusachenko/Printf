/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgusache <sgusache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 13:35:57 by sgusache          #+#    #+#             */
/*   Updated: 2018/12/11 12:02:00 by sgusache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_strsplit(char const *s, char c)
{
	int		len;
	char	**ret;
	int		i;
	int		wc;

	if (!s)
		return (NULL);
	wc = ft_count_words(s, 0, c);
	len = 0;
	ret = (char **)ft_memalloc((wc + 1) * sizeof(char *));
	if (!ret)
		return (NULL);
	i = 0;
	len = 0;
	while (*s)
	{
		len = ft_find_word(s, i++, ret, c);
		s += len;
	}
	ret[wc] = 0;
	return (ret);
}
