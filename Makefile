##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## A Makefile for projetcs
##

CC	=	gcc -Wall -Wextra

RM	=	rm -rf

TEST_CC	=	gcc -Wall -Wextra -I./include --coverage

CFLAGS	+=	-I./include

NAME	=	my_ls

SRCS	=	srcs/ls/my_ls.c \
		srcs/ls/main.c \
		srcs/ls/sorting_functions.c \
		srcs/ls/flags.c \
		srcs/ls/flags_2.c \
		srcs/ls/checks.c \
		srcs/ls/fill_list.c \
		srcs/ls/error.c \
		srcs/ls/printing.c \
		srcs/lists/display_list.c \
		srcs/lists/my_sort_list.c \
		srcs/lists/free_list.c \
		srcs/lists/create_list.c

SRCS_2	=	srcs/ls/my_ls.c \
		srcs/ls/sorting_functions.c \
		srcs/ls/error.c \
		srcs/ls/flags.c \
		srcs/ls/flags_2.c \
		srcs/ls/checks.c \
		srcs/ls/fill_list.c \
		srcs/ls/printing.c \
		srcs/lists/free_list.c \
		srcs/lists/display_list.c \
		srcs/lists/my_sort_list.c \
		srcs/lists/create_list.c

SRCS_TESTS=	tests/test_get_path.c \
		tests/test_my_strcmp_casse.c \
		tests/test_number_path.c

GCDA_FILES=     $(SRCS_2:.c=.gcda) $(SRCS_TESTS:.c=.gcda)

GCNO_FILES=     $(SRCS_2:.c=.gcno) $(SRCS_TESTS:.c=.gcno)

LDFLAGS=	-lcriterion --coverage -L./lib -lmy

TEST_NAME=	units

OBJS	=	$(SRCS:.c=.o)

LIB =		-L./lib -lmy

all:		$(NAME)

tests_run:	EXEC
		./$(TEST_NAME)

./lib/my/libmy.a:
	make -C ./lib/my

EXEC:		./lib/my/libmy.a
		$(TEST_CC) -o $(TEST_NAME) $(SRCS_2) $(SRCS_TESTS) $(LDFLAGS)

$(NAME):	$(OBJS) ./lib/my/libmy.a
		$(CC) $(OBJS) -o $(NAME) $(LIB)

clean:
		$(RM) $(OBJS)
		$(RM) $(GCDA_FILES)
		$(RM) $(GCNO_FILES)
		make -C ./lib/my clean

fclean: 	clean
		$(RM) $(NAME)
		$(RM) $(TEST_NAME)
		$(RM) lib/*.a
		make -C ./lib/my fclean


re:		fclean all

.PHONY:		all exec tests_run clean fclean re