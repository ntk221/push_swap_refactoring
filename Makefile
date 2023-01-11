CC	   = cc
CFLAGS = -Wall -Werror -Wextra

########## search path  ##########

INCLUDE		 = ./includes/
LIBFTPATH    = ./libft/


########## source files ##########

STACK = ./stack/*.c
SORT  = ./sort/*.c
MAIN_HELPER = ./main_helper/*.c


########## test files  ###########

STACK_TESTS  = ./tests/stack_test.c
SORT_TESTS   = ./tests/sort_test.c


############ rules #############

LIBFT     = ./libft/libft.a

$(LIBFT):
	make -C $(LIBFTPATH)

$(NAME): $(LIBFT)
	$(CC) $(STACK) $(NODE) $(MAIN_HELPER) $(SORT) -L$(LIBFTPATH) -I$(INCLUDE) tests/helper.c push_swap.c -o push_swap -lft



PHONY: fclean clean re all

clean:


fclean: clean
	rm push_swap

re: fclean $(NAME)

all: $(NAME)


########### rules for test #############

stack_test:	$(STACK_TESTS) $(LIBFT)
	$(CC) $(STACK_TESTS) $(STACK) $(MAIN_HELPER) -L$(LIBFTPATH) -I$(INCLUDE) tests/helper.c -o stack_test -lft
	./stack_test	
	rm stack_test

sort_test:	$(SORT_TESTS) $(LIBFT)
	$(CC) $(SORT_TESTS) $(SORT) $(STACK) $(MAIN_HELPER) -L$(LIBFTPATH) -I$(INCLUDE) tests/helper.c -o sort_test -lft
	./sort_test
	rm sort_test
