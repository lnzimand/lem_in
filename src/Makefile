FLAGS = -Wall -Werror -Wextra -c

SRCS = ./list_destroy.c ./list_init.c ./list_ins_next.c ./list_rem_next.c

OBJS = ./list_destroy.o ./list_init.o ./list_ins_next.o ./list_rem_next.o

all:
	gcc $(FLAGS) $(SRCS)

clean:
	rm -f $(OBJS)

.PHONY: all clean