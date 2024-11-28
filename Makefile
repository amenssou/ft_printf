NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRCS =  ft_hexa.c ft_pnb.c ft_printf.c ft_strlen.c ft_char.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
