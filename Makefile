NAME = libftprintf.a
SRCS = ft_printf.c ft_printf_fonctions.c

RM = rm -f
CC = gcc $(FLAGS)
CFLAGS = -Wall -Werror -Wextra
OBJS = $(SRCS:.c=.o)

.c.o:
	$(CC) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all re clean fclean