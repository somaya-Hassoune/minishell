NAME = minishell
CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_herdoc.c freetpipe.c builting_commandes/echo.c ft_atoi_.c builting_commandes/ft_unset.c libft/ft_split.c build_in.c shassoun_parsing/syntaxe.c shassoun_parsing/norm.c \
	shassoun_parsing/expand.c builting_commandes/pwd.c  builting_commandes/ft_cd.c builting_commandes/ft_exit.c builting_commandes/export.c \
	builting_commandes/env.c main.c the_pipe.c find_path.c node.c  shassoun_parsing/get_from_env.c shassoun_parsing/is.c shassoun_parsing/strjoinn.c \
	shassoun_parsing/strncp_yy.c shassoun_parsing/check_free.c shassoun_parsing/ft_tocken.c utils1.c shassoun_parsing/pipe_node.c \
	utils2.c utils3.c utils4.c utils5.c utils6.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c  handlers.c

exec_printf = ftprintf/libftprintf.a
exec_libft = libft/libft.a

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)
$(NAME): $(OBJS) $(exec_libft) $(exec_printf)
	$(CC) $(CFLAGS)  $(OBJS) $(exec_libft) $(exec_printf)  -lreadline -o $(NAME)

$(exec_libft):
	make -C libft
$(exec_printf):
	make -C ftprintf

clean :
	make fclean -C ftprintf
	make fclean -C libft
	rm -f $(OBJS)

fclean: clean 
	rm -f $(NAME)

re: fclean all 

.PHONY: all bonus re
