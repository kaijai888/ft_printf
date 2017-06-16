# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kzeng <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/14 17:51:30 by kzeng             #+#    #+#              #
#    Updated: 2016/11/14 17:51:30 by kzeng            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
FLAG = -c -Wall -Wextra -Werror
SRC = ft_isalpha.c \
		ft_isdigit.c \
		ft_isxdigit.c \
		ft_power.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putnbr.c \
		ft_strcmp.c \
		ft_strdup.c \
		ft_strlen.c \
		ft_strnew.c \
		ft_itoa_base.c \
		ft_uitoa_base.c \
		ft_handle_nospec.c \
		ft_handle_int.c \
		ft_handle_int_hash.c \
		ft_handle_int_plusspace.c \
		ft_handle_b.c \
		ft_handle_c.c \
		ft_handle_d_i.c \
		ft_handle_lc.c \
		ft_handle_ls.c \
		ft_handle_o_u.c \
		ft_handle_p.c \
		ft_handle_percent.c \
		ft_handle_s.c \
		ft_handle_x.c \
		ft_printf.c \
		ft_helper.c \
		ft_handler.c \

OBJ = $(SRC:.c=.o)

INC = -I libftprintf.h
RM = rm -rf
AR = ar rc

.PHONY: all clean fclean re test

all: $(NAME)

$(NAME):
	$(CC) $(FLAG) ft_isalpha.c $(INC)
	$(CC) $(FLAG) ft_isdigit.c $(INC)
	$(CC) $(FLAG) ft_isxdigit.c $(INC)
	$(CC) $(FLAG) ft_power.c $(INC)
	$(CC) $(FLAG) ft_putchar.c $(INC)
	$(CC) $(FLAG) ft_putstr.c $(INC)
	$(CC) $(FLAG) ft_putnbr.c $(INC)
	$(CC) $(FLAG) ft_strcmp.c $(INC)
	$(CC) $(FLAG) ft_strdup.c $(INC)
	$(CC) $(FLAG) ft_strlen.c $(INC)
	$(CC) $(FLAG) ft_strnew.c $(INC)
	$(CC) $(FLAG) ft_itoa_base.c $(INC)
	$(CC) $(FLAG) ft_uitoa_base.c $(INC)
	$(CC) $(FLAG) ft_handle_nospec.c $(INC)
	$(CC) $(FLAG) ft_handle_int.c $(INC)
	$(CC) $(FLAG) ft_handle_int_hash.c $(INC)
	$(CC) $(FLAG) ft_handle_int_plusspace.c $(INC)
	$(CC) $(FLAG) ft_handle_b.c $(INC)
	$(CC) $(FLAG) ft_handle_c.c $(INC)
	$(CC) $(FLAG) ft_handle_d_i.c $(INC)
	$(CC) $(FLAG) ft_handle_lc.c $(INC)
	$(CC) $(FLAG) ft_handle_ls.c $(INC)
	$(CC) $(FLAG) ft_handle_o_u.c $(INC)
	$(CC) $(FLAG) ft_handle_p.c $(INC)
	$(CC) $(FLAG) ft_handle_percent.c $(INC)
	$(CC) $(FLAG) ft_handle_s.c $(INC)
	$(CC) $(FLAG) ft_handle_x.c $(INC)
	$(CC) $(FLAG) ft_printf.c $(INC)
	$(CC) $(FLAG) ft_helper.c $(INC)
	$(CC) $(FLAG) ft_handler.c $(INC)
	$(AR) $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

test:
	gcc *.c $(INC) && ./a.out && rm ./a.out