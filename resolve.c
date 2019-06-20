/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgusache <sgusache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 21:57:50 by sgusache          #+#    #+#             */
/*   Updated: 2019/06/20 03:50:56 by sgusache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"

int		resolve(t_printf **factor, va_list ap)
{
	char			*result;
	t_spec_func		func;
	int pr_ret;

	result = NULL;
	pr_ret = 0;
	pr_ret = (*factor)->return_value;
	func = get_spec_func((*factor)->spec);
	if((ft_strchr("dDioOsScCuUpFxf%X", (*factor)->spec) == NULL))
		result = ft_str(factor, ap);
	else
		result = func(factor, ap);
	(*factor)->return_value += ft_strlen(result);
	ft_putstr(result);
	if((ft_strchr("uUd%xXcCoSsp\n", (*factor)->spec) != NULL) && result && ft_strcmp(result, "(null)") != 0 && (*factor)->resul_s != NULL)
		free(result);
	return 0;
}
