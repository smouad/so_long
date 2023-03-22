NAME = so_long

CC = cc

FLAGS = -Wall -Wextra -Werror

RM = rm -rf

LIBFT = libft/libft.a

GNL = $(addprefix get_next_line/, get_next_line.c get_next_line_utils.c)

SRC	= map_comp.c \
		map_shape.c \
		file_extention.c \
		map_path.c \
		error.c \
		so_long.c \


OBJ = $(SRC:.c=.o)

GNLOBJ = $(GNL:.c=.o)

all : $(LIBFT) $(OBJ) $(GNLOBJ)
	$(CC) $(FLAGS) $(OBJ) $(GNLOBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C libft

clean :
	@echo "Cleaning object files ..." 
	@$(RM) $(OBJ) $(GNLOBJ)
	@make clean -C libft
	@echo "Done."
fclean : clean
	@$(RM) $(NAME)
re : clean all
