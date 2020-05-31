FLAGS = -Wall -Werror -Wextra -c

SRCS = ./list_destroy.c ./list_init.c ./list_ins_next.c ./list_rem_next.c ./insert.c \
		./is_member.c ./graph_adjlist.c ./graph_destroy.c ./graph_init.c \
		./graph_ins_edge.c ./graph_ins_vertex.c ./graph_is_adjacent.c ./graph_rem_edge.c \
		./graph_rem_vertex.c ./set_init.c ./queue_enqueue.c ./queue_dequeue.c \
		./breadth_first_search.c ./all_digits.c ./array_length.c ./check_coordinates.c \
		./create_path.c ./error_handler.c ./errors.c ./get_links.c ./get_position.c \
		./get_rooms.c ./graph_alloc.c ./link_alloc.c ./list_alloc.c ./match.c \
		./move_ants.c ./number_of_ants.c ./path_init.c ./path_ins_next.c ./print_array.c \
		./print_graph.c ./print_out.c ./read_input.c ./store_link.c ./path_destroy.c \
		./path_rem_next.c ./print_list.c ./free_array.c ./free_list.c ./free_alloc_mem.c \
		./verify_connections.c ./print_map.c ./copy_graph.c ./insert_rooms.c ./insert_links.c \
		./get_end_start_pos.c ./input_to_array.c

OBJS = ./list_destroy.o ./list_init.o ./list_ins_next.o ./list_rem_next.o ./insert.o \
		./is_member.o ./graph_adjlist.o ./graph_destroy.o ./graph_init.o \
		./graph_ins_edge.o ./graph_ins_vertex.o ./graph_is_adjacent.o ./graph_rem_edge.o \
		./graph_rem_vertex.o ./set_init.o ./queue_enqueue.o ./queue_dequeue.o \
		./breadth_first_search.o ./all_digits.o ./array_length.o ./check_coordinates.o \
		./create_path.o ./error_handler.o ./errors.o ./get_links.o ./get_position.o \
		./get_rooms.o ./graph_alloc.o ./link_alloc.o ./list_alloc.o ./match.o \
		./move_ants.o ./number_of_ants.o ./path_init.o ./path_ins_next.o ./print_array.o \
		./print_graph.o ./print_out.o ./read_input.o ./store_link.o ./path_destroy.o \
		./path_rem_next.o ./print_list.o ./free_array.o ./free_list.o ./free_alloc_mem.o \
		./verify_connections.o ./print_map.o ./copy_graph.o ./insert_rooms.o ./insert_links.o \
		./get_end_start_pos.o ./input_to_array.o


all:
	gcc $(SRCS) -c

clean:
	rm -f $(OBJS)

.PHONY: all clean