FLAGS = -Wall -Werror -Wextra -c

SRCS = ./list_destroy.c ./list_init.c ./list_ins_next.c ./list_rem_next.c ./insert.c \
		./is_member.c ./remove.c ./graph_adjlist.c ./graph_destroy.c ./graph_init.c \
		./graph_ins_edge.c ./graph_ins_vertex.c ./graph_is_adjacent.c ./graph_rem_edge.c \
		./graph_rem_vertex.c ./set_init.c ./queue_enqueue.c ./queue_dequeue.c \
		./breadth_first_search.c

OBJS = ./list_destroy.o ./list_init.o ./list_ins_next.o ./list_rem_next.o ./insert.o \
		./is_member.o ./remove.o ./graph_adjlist.o ./graph_destroy.o ./graph_init.o \
		./graph_ins_edge.o ./graph_ins_vertex.o ./graph_is_adjacent.o ./graph_rem_edge.o \
		./graph_rem_vertex.o ./set_init.o ./queue_enqueue.o ./queue_dequeue.o \
		./breadth_first_search.o

all:
	gcc $(FLAGS) $(SRCS)

clean:
	rm -f $(OBJS)

.PHONY: all clean