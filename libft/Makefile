# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgusache <sgusache@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/06 12:47:40 by sgusache          #+#    #+#              #
#    Updated: 2019/06/01 20:19:05 by sgusache         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
CFLAGS		= -Wall -Werror -Wextra -I. -c
FILES		=	ft_abs.c				\
				ft_itoa.c				\
				ft_memchr.c			\
				fill_str.c  \
				ft_count_words.c \
				ft_find_word.c \
				ft_putendl_fd.c			\
				ft_nbrlen.c			\
				ft_itoa_base.c		\
				ft_strcpy.c			\
				str_rev.c		\
				ft_strmap.c			\
				ft_strsplit.c			\
				ft_lstadd.c			\
				ft_memcmp.c			\
				nb_size.c			\
				ft_putnbr.c			\
				ft_strdel.c			\
				ft_strmapi.c			\
				ft_strstr.c			\
				ft_atoi.c				\
				ft_lstdel.c			\
				ft_memcpy.c			\
				ft_putnbr_fd.c				\
				ft_strdup.c				\
				ft_strncat.c				\
				ft_strsub.c			\
				ft_bzero.c				\
				ft_lstdelone.c				\
				ft_memdel.c				\
				ft_putstr.c				\
				ft_strequ.c				\
				ft_strncmp.c				\
				ft_strtrim.c			\
				ft_isalnum.c				\
				ft_lstiter.c			\
				ft_memmove.c				\
				ft_putstr_fd.c				\
				ft_striter.c				\
				ft_strncpy.c				\
				ft_tolower.c			\
				ft_isalpha.c				\
				ft_lstmap.c				\
				ft_memset.c				\
				ft_strcat.c				\
				ft_striteri.c				\
				ft_strnequ.c				\
				ft_toupper.c			\
				ft_isascii.c				\
				ft_lstnew.c				\
				ft_putchar.c				\
				ft_strchr.c				\
				ft_strjoin.c				\
				ft_strnew.c			\
				ft_isdigit.c				\
				ft_memalloc.c				\
				ft_putchar_fd.c				\
				ft_strclr.c				\
				ft_strlcat.c				\
				ft_strnstr.c			\
				ft_isprint.c				\
				ft_memccpy.c				\
				ft_putendl.c				\
				ft_strcmp.c				\
				ft_strlen.c						\
				ft_strrchr.c			\

OBJ			= $(FILES:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)


$(OBJ): $(FILES)
	gcc $(CFLAGS) $(FILES)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
