CC		= gcc

CFLAGS  = -Wall -Werror -Wextra

SRCS	= push.c reverse_rotate.c rotate.c destroy_stack.c create_stack.c stack_utils.c swap.c simple_operations.c
OBJS	= $(SRCS:%c=%o)
INCLUDE = ../includes/

.c.o: $(OBJS)
			$(CC) $(CFLAGS) -c $(SRCS) -I$(INCLUDE)

clean:
	rm $(OBJS)