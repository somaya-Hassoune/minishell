# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: szine- <szine-@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/06 10:44:39 by szine-            #+#    #+#              #
#    Updated: 2023/12/07 22:41:32 by szine-           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_putchar.c ft_putnbr_base.c ft_putstr.c ft_putnbr.c ft_printf.c ft_putu.c\

OBJS = $(SRCS:.c=.o)

all: $(NAME)
$(NAME): $(OBJS)
$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS)
	ar -rcs $(NAME) $(OBJS)
clean:
	rm -f $(OBJS) $(OBJS1)
fclean: clean
	rm -f $(NAME)
re: fclean all 
.PHONY: all bonus clean  fclean re
   
