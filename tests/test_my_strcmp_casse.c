/*
** EPITECH PROJECT, 2017
** my_my_strcmo_casse.c
** File description:
** sorting alpha test
*/
#include <criterion/criterion.h>
#include "my_ls.h"

int	my_strcmp_casse(char *s1, char *s2);

Test(my_strcmp_casse, return_value_is_good)
{
	char	*str = "ana";
	char	*str_2 = "zoo";

	cr_expect_eq(my_strcmp_casse(str_2, str), my_strcmp(str_2, str));
}

Test(my_strcmp_casse, return_value_is_good_2)
{
	char	*str = "ana";
	char	*str_2 = "zoo";

	cr_expect_eq(my_strcmp_casse(str, str_2), my_strcmp(str, str_2));
}