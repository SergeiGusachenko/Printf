/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgusache <sgusache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 14:50:41 by sgusache          #+#    #+#             */
/*   Updated: 2019/06/19 13:58:31 by sgusache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"

void	exception(char *str)
{
	ft_putstr(str);
	exit(0);
}