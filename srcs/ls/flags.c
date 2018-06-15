/*
** EPITECH PROJECT, 2017
** flags.c
** File description:
** flags function
*/
#include "my_ls.h"

//Function for the -R.
void	option_recursive(struct node *list, char *path)
{
	struct node	*tmp = list;
	struct my_ls	*data;
	char		d_path[256];

	do {
		data = (struct my_ls *)tmp->data;
		if (data->info->d_type == DT_DIR && data->display == true) {
			my_strcpy(d_path, path);
			my_strcat(d_path, "/");
			my_strcat(d_path, data->info->d_name);
			my_ls(d_path, 1);
		}
		tmp = tmp->next;
	} while(tmp != list);
}

//Function for the -l
void	option_l(struct node *list, char *path)
{
	struct node	*tmp = list;
	struct my_ls	*data;
	int		save = 0;

	(void)path;
	do {
		data = (struct my_ls *)tmp->data;
		if (data->display == true && check[A].on == 0)
			save += data->s->st_blocks / 2;
		if (check[A].on == 1)
			save += data->s->st_blocks / 2;
		tmp = tmp->next;
	} while (tmp != list);
	if (check[D].on == 0)
		my_printf("total %d\n", save);
}

//Function for the -a
void	option_a(struct node *list, char *path)
{
	struct node	*tmp = list;
	struct my_ls	*data;

	(void)path;
	do {
		data = (struct my_ls *)tmp->data;
		data->display = true;
		tmp = tmp->next;
	} while (tmp != list);
}

//Function for the -t
void	option_time(struct node *list, char *path)
{
	(void)path;
	my_sort_list(list, &sort_time);
}

//Function for the -d
void	option_d(struct node *list, char *path)
{
	struct node	*tmp = list;
	struct my_ls	*data;

	do {
		data = (struct my_ls *)tmp->data;
		if (my_strcmp(data->info->d_name, ".") == 0) {
			if (my_strcmp(path, ".") != 0)
				my_strcpy(data->info->d_name, path);
			data->display = true;
		}
		else
			data->display = false;
		tmp = tmp->next;
	} while (tmp != list);
}