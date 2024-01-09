CC		=	gcc
SRCS	= srcs/bfs.c srcs/graph.c srcs/lem_in.c srcs/parser.c srcs/queue.c srcs/result.c tools/ft_atoi.c tools/ft_error.c tools/ft_isalnum.c tools/ft_isalpha.c tools/ft_isascii.c tools/ft_isdigit.c tools/ft_isspace.c tools/ft_putchar_fd.c tools/ft_putendl_fd.c tools/ft_putnbr_fd.c tools/ft_putstr_fd.c tools/ft_split.c tools/ft_strchr.c tools/ft_strcmp.c tools/ft_strdup.c tools/ft_strjoin.c tools/ft_strlen.c tools/ft_substr.c tools/get_next_line.c
OBJS	= $(SRCS:.c=.o)
FLAGS	= -Wall -Wextra -Werror
NAME	= lem-in

all: $(NAME)

$(NAME): $(OBJS)
	gcc $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
