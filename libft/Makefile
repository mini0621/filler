NAME = libft.a

CC = gcc 

CFLAGS = -Wall -Werror -Wextra

SRC = ft_lstiter.c    ft_putchar.c    ft_strdel.c     ft_strnew.c  ft_lstlast.c    ft_putchar_fd.c ft_strdup.c     ft_strnstr.c ft_atoi.c  ft_lstlen.c     ft_putendl.c    ft_strequ.c     ft_strrchr.c ft_bzero.c      ft_lstmap.c     ft_putendl_fd.c ft_striter.c    ft_strsplit.c ft_isalnum.c    ft_lstnew.c     ft_putnbr.c     ft_striteri.c   ft_strstr.c ft_isalpha.c    ft_memalloc.c   ft_putnbr_fd.c  ft_strjoin.c    ft_strsub.c ft_isascii.c    ft_memccpy.c    ft_putstr.c     ft_strlcat.c    ft_strtrim.c ft_isdigit.c    ft_memchr.c     ft_putstr_fd.c  ft_strlen.c     ft_tolower.c ft_isprint.c    ft_memcmp.c     ft_sqrt.c       ft_strmap.c     ft_toupper.c ft_itoa.c       ft_memcpy.c     ft_strcat.c     ft_strmapi.c   ft_lstadd.c     ft_memdel.c     ft_strchr.c     ft_strncat.c ft_lstat.c      ft_memmove.c    ft_strclr.c     ft_strncmp.c ft_lstdel.c     ft_memset.c     ft_strcmp.c     ft_strncpy.c ft_lstdelone.c  ft_power.c      ft_strcpy.c     ft_strnequ.c ft_lstpushback.c ft_lstfind.c ft_lstdelof.c ft_strjoinfree.c
OBJ = $(SRC:.c=.o)
INCLUDES = .

.PHONY: all fclean clean &(NAME)

RM = rm -f 

$(NAME):
	$(CC) $(CFLAGS) -c $(SRC) -I $(INCLUDES)
	ar rc $(NAME) $(OBJ)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
