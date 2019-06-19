/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgusache <sgusache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 16:32:45 by sgusache          #+#    #+#             */
/*   Updated: 2019/06/19 13:58:11 by sgusache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"

void	check_u_res(t_printf **f, unsigned long long int *res)
{
	if ((*f)->lenght_result == 1)
		(*res) = (unsigned int)(*res);
	else if ((*f)->lenght_result == 2)
		(*res) = (unsigned short int)(*res);
	else if ((*f)->lenght_result == 3)
		(*res) = (unsigned long int)(*res);
	else if ((*f)->lenght_result == 4)
		(*res) = (unsigned long long int)(*res);
	else if ((*f)->lenght_result == 5)
		(*res) = (uintmax_t)(*res);
	else if ((*f)->lenght_result == NOT_EXIST)
		(*res) = (unsigned int)(*res);
}

char	*manage_p_w(t_printf **f, char *res_str)
{
	char	*w;
	char	*pr;
	int		r_size;
	int		pr_size;

	w = NULL;
	pr = NULL;
	r_size = ft_strlen(res_str);
	if ((*f)->precision > r_size)
	{
		pr_size = (*f)->precision - r_size;
		(*f)->filling_c = '0';
		pr = (char*)ft_memalloc(sizeof(char) * (pr_size + 1));
		fill(f, pr, 0, pr_size);
		res_str = ft_update(pr, ft_strjoin(pr, res_str));
		if ((*f)->flag_h > 0 && (*f)->spec == 'x')
			res_str = ft_update(res_str,
			ft_strjoin(((*f)->spec == 'x') ? "0x" : "0X", res_str));
	}
	if ((*f)->width > (*f)->precision && (*f)->width > r_size)
		m_w(f, &w, &res_str);
	if (pr == NULL && (*f)->flag_m == 0 && (*f)->flag_z > 0 && (*f)->flag_h > 0)
		res_str[1] = ((*f)->spec == 'x') ? 'x' : 'X';
	return (res_str);
}

char	*ft_hex(t_printf **factor, va_list ap)
{
	unsigned long long int	res;
	char					*str;
	int						is_upper;
	int						flag;

	flag = 0;
	is_upper = ((*factor)->spec == 'x') ? 0 : 1;
	res = 0;
	str = NULL;
	get_res_u(factor, ap, &res);
	check_u_res(factor, &res);
	str = (res == 0 && ((*factor)->precision == 0 ||
	(*factor)->precision == 0)) ? ft_strnew(1) : ft_itoa_base_u(res, 16, is_upper);
	if ((*factor)->spec == 'x')
	{
		if ((*factor)->flag_h > 0 && res != 0 && ((*factor)->flag_z == 0
		|| (*factor)->flag_m > 0) && (*factor)->precision < (int)ft_strlen(str))
			str = ft_update(str, ft_strjoin("0x", str));
	}
	else
	{
		if ((*factor)->flag_h > 0 && res != 0
		&& (*factor)->precision < (int)ft_strlen(str) && (*factor)->flag_z == 0)
		{
			str = ft_update(str, ft_strjoin("0X", str));
			flag++;
		}
	}
	str = manage_p_w(factor, str);
	(*factor)->resul_s = str;
	if ((str != NULL && str[0] != '0') || flag)
		free(str);
	return ((*factor)->resul_s);
}
