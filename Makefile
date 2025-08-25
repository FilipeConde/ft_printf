# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/20 19:20:11 by fconde-p          #+#    #+#              #
#    Updated: 2025/08/25 19:25:28 by fconde-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_calloc.c \
	ft_itoa.c \
	ft_memset.c \
	ft_printf.c \
	ft_putchar_fd.c \
	ft_puthex.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c \
	ft_putulhex.c \
	ft_putunbr_fd.c \
	ft_strdup.c \
	ft_strlen.c


OBJ = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wextra -Werror -Wall

bonus:
	$(MAKE) OBJ="$(OBJ)" all


all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $(<) -o $(@)

clean:
	rm -rf $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f libftprintf.a

re: fclean all