FLAGS = -Wall -Werror -Wextra

NAME = lem_in.a

EXE = lem_in

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
	   ./gnl/get_next_line.o ./src/list_init.o ./src/list_destroy.o ./src/list_ins_next.o \
	   ./src/list_rem_next.o ./src/insert.o ./src/is_member.o ./src/graph_adjlist.o \
	   ./src/graph_destroy.o ./src/graph_init.o ./src/graph_ins_edge.o ./src/graph_ins_vertex.o \
	   ./src/graph_is_adjacent.o ./src/graph_rem_edge.o ./src/graph_rem_vertex.o ./src/set_init.o \
	   ./src/queue_enqueue.o ./src/queue_dequeue.o ./src/breadth_first_search.o ./libft/ft_strpos.o \
	   ./src/all_digits.o ./src/array_length.o ./src/check_coordinates.o ./src/create_path.o \
	   ./src/error_handler.o ./src/errors.o ./src/get_links.o ./src/get_position.o ./src/get_rooms.o \
	   ./src/graph_alloc.o ./src/link_alloc.o ./src/list_alloc.o ./src/match.o ./src/move_ants.o \
	   ./src/number_of_ants.o ./src/path_init.o ./src/path_ins_next.o ./src/print_array.o \
	   ./src/print_graph.o ./src/print_out.o ./src/read_input.o ./src/store_link.o \
	   ./src/path_rem_next.o ./src/print_list.o ./src/path_destroy.o ./src/./free_array.o \
	   ./src/free_list.o ./src/free_alloc_mem.o ./src/verify_connections.o ./src/print_map.o \
	   ./src/copy_graph.o ./src/insert_rooms.o ./src/insert_links.o ./src/get_end_start_pos.o \
	   ./src/input_to_array.o

libftmake = $(MAKE) -C libft

gnlmake = $(MAKE) -C gnl

lem_inmake = $(MAKE) -C src

INC = lem_in.h

all: $(NAME)
$(NAME) :
	$(libftmake)
	$(gnlmake)
	$(lem_inmake)
	ar rv $(NAME) $(OBJS) $(INC)
	ranlib $(NAME)
	cc $(FLAGS) lem_in.c -o $(EXE) $(NAME)

clean:
	$(MAKE) -C libft/ clean
	$(MAKE) -C gnl/ clean
	$(MAKE) -C src/ clean

fclean: clean
	rm -f $(NAME) $(EXE)

re: fclean all

.PHONY: all, re, clean, fclean
