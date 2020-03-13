FLAGS = -Wall -Werror -Wextra -c

NAME = lem_in.a

OBJS = ./libft/ft_strchr.o ./libft/ft_strrchr.o ./libft/ft_strstr.o ./libft/ft_strnstr.o \
	   ./libft/ft_strcmp.o ./libft/ft_strncmp.o ./libft/ft_atoi.o ./libft/ft_isalpha.o \
	   ./libft/ft_isdigit.o ./libft/ft_isalnum.o ./libft/ft_isascii.o ./libft/ft_isprint.o \
	   ./libft/ft_toupper.o ./libft/ft_tolower.o ./libft/ft_memalloc.o ./libft/ft_memdel.o \
	   ./libft/ft_strnew.o ./libft/ft_strdel.o ./libft/ft_strclr.o ./libft/ft_striter.o \
	   ./libft/ft_striteri.o ./libft/ft_strmap.o ./libft/ft_strmapi.o ./libft/ft_strequ.o \
	   ./libft/ft_strnequ.o ./libft/ft_strsub.o ./libft/ft_strjoin.o ./libft/ft_strtrim.o \
	   ./libft/ft_strsplit.o ./libft/ft_itoa.o ./libft/ft_putchar.o ./libft/ft_putstr.o \
	   ./libft/ft_putendl.o ./libft/ft_putnbr.o ./libft/ft_putchar_fd.o ./libft/ft_putstr_fd.o \
	   ./libft/ft_putendl_fd.o ./libft/ft_putnbr_fd.o ./libft/ft_strrev.o ./libft/ft_bzero.o \
	   ./libft/ft_lstdel.o ./libft/ft_lstdelone.o ./libft/ft_lstiter.o ./libft/ft_lstnew.o \
	   ./libft/ft_memccpy.o ./libft/ft_memchr.o ./libft/ft_memcmp.o ./libft/ft_memcpy.o \
	   ./libft/ft_memmove.o ./libft/ft_memset.o ./libft/ft_strcat.o ./libft/ft_strcpy.o \
	   ./libft/ft_strdup.o ./libft/ft_strlcat.o ./libft/ft_strlen.o ./libft/ft_atol.o \
	   ./libft/ft_strncat.o ./libft/ft_strncpy.o ./libft/ft_lstadd.o ./libft/ft_isspace.o\
	   ./gnl/get_next_line.o

libftmake = $(MAKE) -C libft

gnlmake = $(MAKE) -C gnl

INC = 

all: $(NAME)
$(NAME) :
	$(libftmake)
	$(gnlmake)
	ar rv $(NAME) $(OBJS) $(INC)
	ranlib $(NAME)

clean:
	$(MAKE) -C libft/ clean
	$(MAKE) -C gnl/ clean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, re, clean, fclean