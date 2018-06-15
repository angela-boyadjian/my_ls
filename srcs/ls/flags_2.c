/*
** EPITECH PROJECT, 2017
** flags_2.c
** File description:
** flags function next
*/
#include "my_ls.h"

//Checks rights function.
void check_rights(struct my_ls *tmp)
{
	if (S_ISCHR(tmp->s->st_mode))
		my_printf((S_ISCHR(tmp->s->st_mode)) ? "c" : "-");
	else
		my_printf((S_ISDIR(tmp->s->st_mode)) ? "d" : "-");
}

//Function for -o. 
void	option_o(struct node *list, char *path)
{
	(void)path;
	option_l(list, path);
}

//Function for -S.
void	option_big_s(struct node *list, char *path)
{
	(void)path;
	my_sort_list(list, &sort_size);
}