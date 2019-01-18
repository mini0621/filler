NAME = mnishimo.filler

CC = gcc 

FLAGS = -Wall -Werror -Wextra

INCLUDES = .
HEADER = player.h get_next_line.h

SRC = player.c parsing.c piece.c
OBJ = $(SRC:.c=.o)

.PHONY : clean fclean all
RM = rm -f 


%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $^ -I $(INCLUDES)

$(NAME):$(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
