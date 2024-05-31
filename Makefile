NAME =          push_swap

SRCS =  main.c\
		n_guard.c\
		stacks.c\
		utils.c\
		oper_swap.c\
		oper_push.c\
		oper_rotate.c\
		oper_reverse.c\
		sort.c

LIB = libft/libft.a\
		ft_printf/libftprintf.a\
		get_next_line/gnl.a

HEADR = push_swap.h

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

OBJS = $(SRCS:.c=.o)

all: $(LIB) $(NAME)

$(LIB):
	@make re -C ./libft
	@make re -C ./ft_printf
	@make re -C ./get_next_line

$(NAME): $(OBJS) $(HEADR)
	$(CC) $(SRCS) $(CFLAGS) $(LIB) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
clean:
	@make clean -C ./libft
	@make clean -C ./ft_printf
	@make clean -C ./get_next_line
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIB)

re: fclean all

.PHONY: all clean fclean re

