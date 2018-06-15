/*
** EPITECH PROJECT, 2017
** error.c
** File description:
** error handling
*/
#include "my_ls.h"

//Error handling.
int	errors(int ac, char **av)
{
	if (check_flags(av, ac) == FAILURE) {
		my_print_err("Invalid option\n");
		return (FAILURE);
	}
	return (SUCCESS);
}