CC	   = gcc

STACK = ./stack/*.c
SORT  = ./sort/*.c
UTILS = ./utils/*.c 

CFLAGS = -Wall -Werror -Wextra

# OBJ = $(%c=%o)

STACK_TESTS  = ./tests/stack_test.c
SORT_TESTS   = ./tests/sort_test.c

NAME = push_swap

$(NAME):
	$(CC) $(STACK) $(NODE) $(UTILS) $(SORT) push_swap.c -o push_swap 

.PHONY:
fclean:
	rm push_swap

stack_test:	$(STACK_TESTS)
	$(CC) $(STACK_TESTS) $(STACK) $(UTILS) -o stack_test
	./stack_test	
	rm stack_test

sort_test:	$(SORT_TESTS)
	$(CC) $(SORT_TESTS) $(SORT) $(STACK) $(UTILS) -o sort_test
	./sort_test
	rm sort_test
