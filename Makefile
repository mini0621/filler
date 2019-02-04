NAME = mnishimo.filler

CC = gcc 

FLAGS = -Wall -Werror -Wextra

INCLUDES = ./includes/
LIB = libftprintf/
HEADER = player.h get_next_line.h


SRC = get_next_line.c player.c parsing.c map.c solver.c piece.c coord.c point.c
OBJ = $(SRC:.c=.o)

RM = rm -f 

LIBFT = libftprintf.a

.PHONY : clean fclean all

%.o : %.c
	$(CC) $(FLAGS) -I $(INCLUDES) -c $^ 


$(NAME):$(OBJ)
	make -C libftprintf/ libftprintf.a
	$(CC) $(FLAGS) -I $(INCLUDES) -o $(NAME) $(OBJ) -L $(LIB) -lftprintf

all: $(NAME)

clean:
	$(RM) $(OBJ)
	make -C libftprintf/ clean

fclean: clean
	$(RM) $(NAME)
	make -C libftprintf/ fclean

re: fclean all
