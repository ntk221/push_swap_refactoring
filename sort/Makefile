CC		= gcc

CFLAGS  = -Wall -Werror -Wextra

SRCS	= sort_utils.c sort.c
OBJS	= $(SRCS:%c=%o)
INCLUDE = ../includes/

.o: $(OBJS)
			$(CC) $(CFLAGS) -I$(INCLUDE)  -c $(SRCS)

clean:
	rm $(OBJS)

test:
	$(CC) -c -I$(INCLUDE) sort_test.c
	$(CC) $(OBJS) -o sort_test
