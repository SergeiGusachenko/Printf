/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgusache <sgusache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 21:35:50 by sgusache          #+#    #+#             */
/*   Updated: 2019/06/20 04:12:09 by sgusache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"

static void		init_funcs(t_spec_func *func)
{
	func['d'] = &ft_int;
	func['D'] = &ft_int;
	func['i'] = &ft_int;
	func['o'] = &ft_oct;
	func['O'] = &ft_oct;
	func['s'] = &ft_str;
	func['S'] = &ft_str;
	func['c'] = &ft_char;
	func['C'] = &ft_char;
	func['u'] = &ft_uns;
	func['U'] = &ft_uns;
	func['p'] = &ft_point;
	func['x'] = &ft_hex;
	func['f'] = &ft_float;
	func['F'] = &ft_float;
	func['%'] = &ft_proc;
	func['X'] = &ft_hex;
}

t_spec_func		get_spec_func(char specifier)
{
	static t_spec_func *funcs;

	if (!funcs)
	{
		funcs = malloc(sizeof(*funcs) * NUM_SPEC);
		if (funcs)
			init_funcs(funcs);
	}
	return (funcs[(int)specifier]);
}
