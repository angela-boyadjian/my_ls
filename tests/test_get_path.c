/*
** EPITECH PROJECT, 2017
** test_get_path.c
** File description:
** testing function
*/
#include <criterion/criterion.h>
#include "my_ls.h"

char *get_path(int ac, char **av);

Test(get_path, return_value_is_good)
{
	char *av[] = {"./my_ls", "-l", "srcs"};

	cr_expect_str_eq(get_path(3, av), "srcs");
}

Test(get_path, return_value_is_good_2)
{
	char *av[] = {"./my_ls", "-l"};

	cr_expect_str_eq(get_path(2, av), ".");
}