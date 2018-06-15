/*
** EPITECH PROJECT, 2017
** fill_list.h
** File description:
** fill linked list
*/
#include "my_ls.h"

//Initialize void *data.
static	struct my_ls *init_data(char *path, struct dirent *name)
{
	struct my_ls	*data = malloc(sizeof(struct my_ls));

	data->s = malloc(sizeof(struct stat));
	stat(path, (data->s));
	data->info = name;
	data->pwd = getpwuid(data->s->st_uid);
	data->grp = getgrgid(data->s->st_gid);
	if (data->info->d_name[0] == '.')
		data->display = false;
	else
		data->display = true;
	return (data);
}

//Function to fill when it's a file.
static	void file(struct node **list, char *path)
{
	struct dirent	*info;

	info = malloc(sizeof(struct dirent));
	my_strcpy(info->d_name, path);
	insert_end(list, init_data(path, info));
}

//Function to fill when it's a directory.
static	void directory(struct node **list, char *path, DIR *d)
{
	struct dirent	*info;
	char		d_path[256];

	while ((info = readdir(d)) != NULL) {
		my_strcpy(d_path, path);
		my_strcat(d_path, "/");
		my_strcat(d_path, info->d_name);
		insert_end(list, init_data(d_path, info));
		*list = (*list)->next;
	}
}

//Fills the linked list.
DIR	*fill_list(struct node **list, char *path)
{
	DIR	*d;

	d = opendir(path);
	if (d == NULL) {
		file(list, path);
		return (d);
	}
	directory(list, path, d);
	return (d);
}
