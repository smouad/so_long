SRCS	= ft_printf.c ft_putchar.c ft_putstr.c\
			ft_putnbr.c ft_putnbr_u.c ft_puthexa.c ft_putad.c\
			
OBJS	= ${SRCS:.c=.o}

FLAGS	= 	-Wall -Wextra -Werror

NAME = libftprintf.a

$(NAME)	:
		 cc $(FLAGS) -c $(SRCS)
		 ar rc $(NAME) $(OBJS)

all: $(NAME)

clean:
		rm -rf $(OBJS)

fclean: clean
		rm -rf $(NAME)

re: fclean all