  /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgusache <sgusache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 23:58:19 by sgusache          #+#    #+#             */
/*   Updated: 2019/05/07 22:31:51 by sgusache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <stdarg.h>
# include <stdint.h>
# include <limits.h>
#include <stddef.h>
# include "../libft/libft.h"
# define STAR -42
# define NUM_SPEC 256
# define NOT_INIT 'b'
# define NOT_EXIST -1
# define PROBLEM 10000
# define PROBLE -10000


typedef struct				s_printf
{
	char					filling_c;
	int						flag_result;
	int						lenght_result;
	int						width;
	char					sign;
	int						precision;
	va_list					args;
	const char *restrict	format;
	int						flag_m;
	int						flag_p;
	int						flag_z;
	int						flag_s;
	int						flag_h;
	char					spec;
	int						return_value;
	int						upper_case;
	char					*resul_s;
}							t_printf;

typedef char*				(*t_spec_func)(t_printf**, va_list);
void						get_res_u(t_printf **f, va_list ap, unsigned long long int *res);
void						m_w(t_printf **f, char **w,char	**res);
int							ft_nbrlen_u(unsigned long long int n, int base);
char						*ft_strrev_u(char *str);
char						*fill_str_u(char *str, unsigned long long int nb, int i);
char						*ft_itoa_u(unsigned long long int n);
int							nb_size_u(unsigned long long int nb);
char						*ft_itoa_base_u(unsigned long long int n, int base, int uppercase);
char						*ft_update(char *str, char *update);
char						*ft_proc(t_printf **factor, va_list ap);
char						*ft_itoa_base_u(unsigned long long int n, int base, int uppercase);
char						*ft_float_itoa(long long int frac, long long int exp, int precision);
long long int				ft_modf(long double res, int pr, long long int *res_int);
char						*first_char(t_printf **f, char **width, long long int res);
char						*manage_int_w(t_printf **f, char *pr, long long int value);
char						*manage_pr(t_printf **f, char *pr, long long int value);
char						*manage_w(t_printf **f, char *w, char **res);
char						*manage_res(t_printf **f, char **w, char **pr, long long int res);
char						*ft_float(t_printf **factor, va_list ap);
void						allocate(t_printf **f, char **precision, char **width, long long int *res);
void						fill(t_printf **f, char *str,int start,int end);
char						*logic(t_printf **factor, va_list ap);
char						*ft_hex(t_printf **factor, va_list ap);
char						*ft_int(t_printf **factor, va_list ap);
int							exec_width(t_printf **factor, int res);
int							exec_precision(t_printf **factor, int res);
int							nb_uns_size(unsigned long long int nb);
char						*ft_long_itoa(unsigned long long int res);
void						get_result(t_printf **f, va_list ap, long long int *res);
char						*ft_point(t_printf **factor, va_list ap);
char						*ft_oct(t_printf **factor, va_list ap);
char						*ft_char(t_printf **factor, va_list ap);
char						*ft_str(t_printf **factor, va_list ap);
char						*ft_int(t_printf **factor, va_list ap);
char						*ft_uns(t_printf **factor, va_list ap);
int							ft_printf(const char *restrict format, ...);
void						check_flags(t_printf **factor, int *i);
void						parse(t_printf **factor, int *i, va_list ap);
void						exception(char *str);
void						init(t_printf **factor, const char *restrict format);
void						check_specifier(t_printf **factor, int *i);
void						check_width(t_printf **factor, int *i, va_list ap);
void						check_precision(t_printf **factor, int *i, va_list ap);
void						check_lenght(t_printf **format, int *i);
t_spec_func					get_spec_func(char specifier);
int							resolve(t_printf **factor, va_list ap);

#endif
