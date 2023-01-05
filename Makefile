CC	   = gcc

STACK = ./stack/*.c
SORT  = ./sort/*.c
MAIN_HELPER = ./main_helper/*.c


CFLAGS = -Wall -Werror -Wextra

# OBJ = $(%c=%o)

STACK_TESTS  = ./tests/stack_test.c
SORT_TESTS   = ./tests/sort_test.c

INCLUDE		 = includes/

LIBFT_DIR = libft/

NAME = push_swap

$(NAME): lib
	$(CC) $(STACK) $(NODE) $(MAIN_HELPER) $(SORT) -I/$(INCLUDE) tests/helper.c $(LIBFT_DIR)libft.a push_swap.c -o push_swap 

lib:
	make re -C $(LIBFT_DIR)

.PHONY:
fclean:
	rm push_swap

stack_test:	$(STACK_TESTS) lib
	$(CC) $(STACK_TESTS) $(STACK) $(MAIN_HELPER) tests/helper.c $(LIBFT_DIR)libft.a -o stack_test
	./stack_test	
	rm stack_test

sort_test:	$(SORT_TESTS) lib
	$(CC) $(SORT_TESTS) $(SORT) $(STACK) $(MAIN_HELPER) tests/helper.c $(LIBFT_DIR)libft.a -o sort_test
	./sort_test
	rm sort_test
