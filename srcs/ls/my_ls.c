/*
** EPITECH PROJECT, 2017
** my_ls.c
** File description:
** my_ls function
*/
#include "my_ls.h"

struct options check[NB_OPTIONS] = {
	{"l", 0, &option_l},
	{"d", 0, &option_d},
	{"t", 0, &option_time},
	{"a", 0, &option_a},
	{"r", 0, NULL},
	{"R", 0, NULL},
	{"o", 0, &option_o},
	{"S", 0, &option_big_s}
};

//Returns the path.
char	*get_path(int ac, char **av)
{
	static int	i = 1;
	static bool	ret = false;

	for (; i < ac && av[i][0] == '-'; ++i);
	if (ret == false && i == ac) {
		ret = true;
		return (".");
	}
	if (i == ac)
		return (NULL);
	ret = true;
	return (av[i++]);
}

//Handles display depending on options
static	void do_ls(struct node *list)
{
	if (check[R].on == 1)
		display_reverse(list, &print_list);
	else
		display_list(list, &print_list);
}

//My_ls function.
void	my_ls(char *path, int display_path)
{
	DIR		*d;
	int		j;
	struct node	*list = NULL;

	if ((display_path > 0 || check[REC].on == 1) && check[D].on == 0)
		my_printf("%s:\n", path);
	d = fill_list(&list, path);
	my_sort_list(list, &sort_alpha);
	for (j = 0; j < NB_OPTIONS; ++j) {
		if (check[j].on == 1 && check[j].ptr != NULL)
			(check[j].ptr)(list, path);
	}
	do_ls(list);
	if (display_path > 0 || check[REC].on == 1)
		my_printf("\n\n");
	if (check[REC].on == 1)
		option_recursive(list, path);
	closedir(d);
}

//Returns the number of paths.
int	number_path(int ac, char **av)
{
	int	i = 1;
	int	j = 0;

	for (; i < ac; ++i) {
		if (av[i][0] != '-')
			++j;
	}
	return (j);
}