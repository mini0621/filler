NAME = mnishimo.filler

CC = gcc 

FLAGS = -Wall -Werror -Wextra

INCLUDES = .
LIB = libft/
HEADER = player.h get_next_line.h


SRC = get_next_line.c player.c parsing.c piece.c solver.c
OBJ = $(SRC:.c=.o)

RM = rm -f 

LIBFT = libft.a

.PHONY : clean fclean all

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -I $(INCLUDES)


$(NAME):$(OBJ)
	make -C libft/ re
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L $(LIB) -lft

all: $(NAME)

clean:
	$(RM) $(OBJ)
	make -C libft/ clean

fclean: clean
	$(RM) $(NAME)
	make -C libft/ fclean

re: fclean all
