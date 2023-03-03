NAME = so_long

CC = cc

FLAGS = -Wall -Wextra -Werror

RM = rm -rf

LIBFT = libft/libft.a

GNL = $(addprefix get_next_line/, get_next_line.c get_next_line_utils.c)

SRC = map_comp.c \
		so_long.c \

OBJ = $(SRC:.c=.o)
GNLOBJ = $(GNL:.c=.o)

all : $(LIBFT) $(OBJ) $(GNLOBJ)
	$(CC) $(FLAGS) $(OBJ) $(GNLOBJ) $(LIBFT)

$(LIBFT):
	make -C libft

clean :
	$(RM) $(OBJ) $(GNLOBJ) a.out
	make clean -C libft
re : clean all
