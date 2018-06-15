/*
** EPITECH PROJECT, 2017
** checks.c
** File description:
** cheking functions
*/
#include "my_ls.h"

//Check if flag is valid and set on 1 if so.
int	validate_flags(char *str)
{
	int	j;

	for (int i = 0; str[i]; ++i) {
		for (j = 0; j < NB_OPTIONS; ++j) {
			if ((check[j].flag)[0] == str[i]) {
				check[j].on = 1;
				break;
			}
		}
		if (j == NB_OPTIONS)
			return (FAILURE);
	}
	return (SUCCESS);
}

//Checks if there are flags.
int	check_flags(char **av, int ac)
{
	int	i;

	for (i = 1; i < ac; ++i) {
		if (av[i][0] == '-' && validate_flags(av[i] + 1) == FAILURE)
			return (FAILURE);
	}
	return (SUCCESS);
}