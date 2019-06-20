/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgusache <sgusache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 09:30:55 by sgusache          #+#    #+#             */
/*   Updated: 2019/06/20 01:04:02 by sgusache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"

char	*ft_char(t_printf **factor, va_list ap)
{
	char	*res;
	char	*wd;

	wd = NULL;

	res = (char*)malloc(sizeof(char) * 3);
	res[1] = '\0';
	res[0] = (char)va_arg(ap, int);
	if (res[0] == (int)NULL)
		res[0] = '\0';
	if ((*factor)->width != NOT_EXIST && res[0] != (int)NULL)
		wd = manage_w(factor, wd, &res);
	if (res[0] == 0)
	{
		wd = manage_w(factor, wd, &res);
		if (wd != NULL)
			ft_putstr(wd);
		(*factor)->return_value += (wd != NULL) ? ft_strlen(wd) + 1 : 1;
		if (wd != NULL)
			free(wd);
		ft_putchar('\0');
		return (NULL);
	}
	if (wd != NULL)
		return (wd);
	(*factor)->resul_s = ft_strdup(res);
	if (res != NULL && res[0] != '0')
		free(res);
	return ((*factor)->resul_s);
}
