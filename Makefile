CC	   = cc

STACK = ./stack/*.c
SORT  = ./sort/*.c
MAIN_HELPER = ./main_helper/*.c


CFLAGS = -Wall -Werror -Wextra

# OBJ = $(%c=%o)

STACK_TESTS  = ./tests/stack_test.c
SORT_TESTS   = ./tests/sort_test.c

INCLUDE		 = includes/

NAME = push_swap

LIBFTDIR = libft
LIBFT = libft/libft.a

$(NAME): $(LIBFT)
	$(CC) $(STACK) $(NODE) $(MAIN_HELPER) $(SORT) -I/$(INCLUDE) tests/helper.c $(LIBFT) push_swap.c -o push_swap 

$(LIBFT):
	make -C $(LIBFTDIR)

PHONY:fclean clean re all
fclean:
	rm push_swap

clean:

re: fclean $(NAME)

all: $(NAME)

stack_test:	$(STACK_TESTS)
	$(CC) $(STACK_TESTS) $(STACK) $(MAIN_HELPER) tests/helper.c $(LIBFT) -o stack_test
	./stack_test	
	rm stack_test

sort_test:	$(SORT_TESTS)
	$(CC) $(SORT_TESTS) $(SORT) $(STACK) $(MAIN_HELPER) tests/helper.c $(LIBFT) -o sort_test
	./sort_test
	rm sort_test
