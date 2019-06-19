/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgusache <sgusache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 14:37:06 by sgusache          #+#    #+#             */
/*   Updated: 2019/06/19 14:20:31 by sgusache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"

char	*ft_point(t_printf **factor, va_list ap)
{
	unsigned long	res;
	char			*str_res;
	char			*w;
	char			*tmp;

	tmp = NULL;
	str_res = NULL;
	w = NULL;
	res = va_arg(ap, unsigned long);
	str_res = ft_itoa_base(res, 16, 0);
	str_res = ft_update(str_res, ft_strjoin("0x", str_res));
	if ((*factor)->width != NOT_EXIST)
		m_w(factor, &w, &str_res);
	tmp = str_res;
	free(str_res);
	return (str_res);
}
