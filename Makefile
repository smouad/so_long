
NAME = so_long

CC = cc

FLAGS = -Wall -Wextra -Werror

RM = rm -rf

LIBFT = libft/libft.a

LIBPRINTF = ft_printf/libftprintf.a

GNL = $(addprefix get_next_line/, get_next_line.c get_next_line_utils.c)

SRC	= map_comp.c \
		map_shape.c \
		file_extention.c \
		map_path.c \
		error.c \
		so_long.c \
		initialising.c \
		hooks.c \
		move.c \


OBJ = $(SRC:.c=.o)

GNLOBJ = $(GNL:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) $(GNLOBJ) $(LIBPRINTF) $(LIBFT) so_long.h
	$(CC) $(FLAGS) $(OBJ) $(GNLOBJ) $(LIBFT) $(LIBPRINTF) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(LIBFT):
	make -C libft

$(LIBPRINTF):
	make -C ft_printf

clean :
	$(RM) $(OBJ) $(GNLOBJ)
	make clean -C libft
	make clean -C ft_printf
fclean : clean
	$(RM) $(NAME)
	make fclean -C libft
	make fclean -C ft_printf
re : clean all
