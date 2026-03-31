# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: szine- <szine-@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/11 21:13:13 by szine-            #+#    #+#              #
#    Updated: 2023/12/03 14:04:31 by szine-           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_isascii.c ft_memmove.c ft_strchr.c ft_strncmp.c \
        ft_isdigit.c ft_memset.c ft_strdup.c ft_strnstr.c \
        ft_isprint.c ft_putchar_fd.c ft_striteri.c ft_strrchr.c \
        ft_atoi.c ft_itoa.c ft_putendl_fd.c ft_strjoin.c ft_strtrim.c \
        ft_bzero.c ft_putnbr_fd.c ft_strlcat.c ft_substr.c \
        ft_calloc.c ft_memchr.c ft_strlcpy.c ft_tolower.c \
        ft_isalnum.c ft_memcmp.c ft_putstr_fd.c ft_strlen.c ft_toupper.c \
        ft_isalpha.c ft_memcpy.c  ft_strmapi.c ft_split.c

SRCS1 =  ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c \
         ft_lstiter_bonus.c ft_lstlast_bonus.c \
        ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c ft_lstdelone_bonus.c

OBJS = $(SRCS:.c=.o)
OBJS1 = $(SRCS1:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS)
	ar -rcs $(NAME) $(OBJS)

bonus: $(OBJS1)
	
$(OBJS1): $(SRCS1)
	$(CC) $(CFLAGS) -c $(SRCS1)
	ar -rcs $(NAME) $(OBJS1)

clean:
	rm -f $(OBJS) $(OBJS1)

fclean: clean
	rm -f $(NAME)

re: fclean all 

.PHONY: all bonus clean  fclean re
