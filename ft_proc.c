/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgusache <sgusache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 13:22:43 by sgusache          #+#    #+#             */
/*   Updated: 2019/06/19 14:20:39 by sgusache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"


void	m_w(t_printf **f, char **w, char **res)
{
	int size;

	size = 0;
	size = (*f)->width;
	if ((*f)->spec != '%')
		size = (*f)->width - ft_strlen(*res) + 1;
	(*f)->filling_c = ' ';
	if (size >= 1)
	{
		(*w) = (char *)ft_memalloc(sizeof(char) * size);
		if ((*f)->flag_m == 0 && ((*f)->flag_z > 0) &&
		(*f)->spec != 'p' && (*f)->precision == NOT_EXIST)
			(*f)->filling_c = '0';
		fill(f, (*w), 0, size - 1);
		if ((*f)->flag_m > 0)
			*res = ft_strjoin(*res, *w);
		else
			*res = ft_strjoin(*w, *res);
	}
}

char	*ft_proc(t_printf **factor, va_list ap)
{
	char	*res;
	char	*wd;

	wd = NULL;
	if ((*factor)->spec == NOT_EXIST)
		va_arg(ap, int);
	res = (char*)malloc(sizeof(char) * 2);
	res[1] = '\0';
	res[0] = '%';
	if ((*factor)->width != NOT_EXIST)
		m_w(factor, &wd, &res);
	(*factor)->resul_s = res;
	free(res);
	return ((*factor)->resul_s);
}
