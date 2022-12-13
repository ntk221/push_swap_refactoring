CC	   = gcc

STACK = ./stack/*.c
NODE  = ./node/*.c

CFLAGS = -Wall -Werror -Wextra

STACK_TESTS  = ./tests/stack_test.c
NODE_TESTS   = ./tests/node_test.c

NAME = push_swap

all:
	$(CC) $(STACK) $(NODE) push_swap.c -o push_swap 

test:	$(STACK_TESTS)
	$(CC) $(STACK_TESTS) $(STACK) -o stack_test
	./stack_test	
	rm stack_test
