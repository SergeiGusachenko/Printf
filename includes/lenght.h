/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lenght.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgusache <sgusache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 04:52:47 by sgusache          #+#    #+#             */
/*   Updated: 2019/06/21 01:03:38 by sgusache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LENGHT_H
# define LENGHT_H
# define NUM_LENGHT 8

typedef struct		s_lenght
{
	char	*flag;
	int		num;
}					t_lenght;

t_lenght		g_arr_leng[NUM_LENGHT] = {
	{"hh", 1},
	{"h", 2},
	{"l", 3},
	{"ll", 4},
	{"j", 5},
	{"z", 6},
	{"t", 7},
	{"L", 8}
};

#endif
