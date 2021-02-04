##
## EPITECH PROJECT, 2020
## my_printf Makefile - Amoz Pay
## File description:
## main makefile
##

NAME    =       libmy.a

SRC	=	SRC/my_printf1.c		\
		SRC/my_save_nbr_base.c		\
		SRC/my_printf2.c		\
		SRC/my_printf3.c		\
		SRC/my_printf4.c		\
		SRC/my_printf5.c		\
		SRC/my_sprintf.c		\
		SRC/flag_processing.c		\
		SRC/flag_processing2.c		\
		SRC/padding_flags.c		\
		SRC/my_compute_power_rec.c	\
		SRC/my_putstr.c			\
		SRC/my_str_isalpha.c		\
		SRC/my_strncmp.c		\
		SRC/my_compute_square_root.c	\
		SRC/my_revstr.c			\
		SRC/my_str_islower.c		\
		SRC/my_strncpy.c		\
		SRC/my_find_prime_sup.c		\
		SRC/my_str_isnum.c		\
		SRC/my_strstr.c			\
		SRC/my_getnbr.c			\
		SRC/my_str_isprintable.c	\
		SRC/my_strupcase.c		\
		SRC/my_isneg.c			\
		SRC/my_strcapitalize.c		\
		SRC/my_str_isupper.c		\
		SRC/my_swap.c			\
		SRC/my_is_prime.c		\
		SRC/my_strcat.c			\
		SRC/my_strlen.c			\
		SRC/my_putchar.c		\
		SRC/my_strcmp.c			\
		SRC/my_strlowcase.c		\
		SRC/my_put_nbr.c		\
		SRC/my_strcpy.c			\
		SRC/my_strncat.c		\
		SRC/replace_no_print.c		\
		SRC/replace_purcent.c	\
		SRC/my_puterr.c

OBJ	=		$(SRC:.c=.o)

HEADERS	=		-I includes

TEST_NAME	=	unit_tests

TEST_FILES	=	tests/tests_save_number_base.c		\
			tests/tests_parsing_count.c		\
			tests/tests_output_loading.c


FUNC_TEST = func_test

all: $(NAME)

$(NAME):
	@gcc -c $(SRC) $(HEADERS)
	@mv *.o SRC/
	@ar rc $(NAME) $(OBJ) 
	@mv $(NAME) ../

$(FUNC_TEST): 	fclean
		@gcc -o $(FUNC_TEST) $(SRC) SRC/main.c $(HEADERS) $(LIB) -g3

clean:
	@rm -f $(OBJ) main.o
	@rm -f *.g*

fclean: clean
	@rm -f ../$(NAME) $(TEST_NAME) $(FUNC_TEST)

re:	fclean $(NAME)



$(TEST_NAME):	re
		gcc -o $(TEST_NAME) $(TEST_FILES) -I includes -L. -lmy --coverage -lcriterion

run_tests:	$(TEST_NAME)
		./$(TEST_NAME)
		gcovr
