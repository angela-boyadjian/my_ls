/*
** EPITECH PROJECT, 2017
** test_number_path.c
** File description:
** testing function
*/
#include <criterion/criterion.h>
#include "my_ls.h"

int number_path(int ac, char **av);

Test(number_path, return_value_is_good)
{
	char *av[] = {"./my_ls", "-l", "srcs"};

	cr_expect_eq(number_path(3, av), 1);
}

Test(number_path, return_value_is_good_2)
{
	char *av[] = {"./my_ls", "-l", "srcs", "lib"};

	cr_expect_eq(number_path(4, av), 2);
}

