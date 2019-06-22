# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgusache <sgusache@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/30 15:47:30 by sgusache          #+#    #+#              #
#    Updated: 2019/06/21 01:05:18 by sgusache         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = ft_proc.c\
				ft_printf.c\
				ft_float.c\
				ft_hex.c\
				ft_point.c\
				ft_uns.c\
				hendlers.c\
				ft_char.c\
				ft_str.c\
				utils.c\
				ft_oct.c\
				initialize.c\
				logic.c\
				ft_int.c\
				resolve.c\
				dispatch.c \
				format_check.c\
				libft/*.c


NAME	=	libftprintf.a


OBJECTS	:=	$(SOURCES:.c=.o)

all:		$(NAME)

$(NAME):
			gcc -Wall -Wextra -Werror -I /includes/header.h -c $(SOURCES)
			ar rcs $(NAME) *.o
clean:
			make -C libft/ clean
			rm -rf *.o

fclean:		clean
			make -C libft/ fclean
			rm -rf $(NAME)

re:		fclean all
			make -C libft/ re
