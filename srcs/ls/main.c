/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** main for ls
*/
#include "my_ls.h"

//Main function.
int main(int ac, char **av)
{
	int	display_path = number_path(ac, av);
	char	*path;

	if (errors(ac, av) == FAILURE)
		return (FAILURE);
	while ((path = get_path(ac, av)) != NULL)
		my_ls(path, display_path - 1);
	return (SUCCESS);
}