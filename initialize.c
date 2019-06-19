/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgusache <sgusache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 20:30:45 by sgusache          #+#    #+#             */
/*   Updated: 2019/06/19 13:54:28 by sgusache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"

void	init(t_printf **factor, const char *restrict format)
{
	(*factor)->format = format;
	(*factor)->lenght_result = NOT_EXIST;
	(*factor)->return_value = 0;
	(*factor)->width = NOT_EXIST;
	(*factor)->precision = NOT_EXIST;
	(*factor)->filling_c = NOT_INIT;
	(*factor)->flag_result = NOT_EXIST + 1;
	(*factor)->flag_z = 0;
	(*factor)->flag_p = 0;
	(*factor)->flag_h = 0;
	(*factor)->flag_s = 0;
	(*factor)->flag_m = 0;
}
