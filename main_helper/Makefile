CC		= gcc

CFLAGS  = -Wall -Werror -Wextra

SRCS	= compression.c error.c arguments_check.c
OBJS	= $(SRCS:%c=%o)
INCLUDE = ../includes/

.c.o: $(OBJS)
			$(CC) $(CFLAGS) -c $(SRCS) -I$(INCLUDE)


clean:
	rm $(OBJS)