/*
** EPITECH PROJECT, 2017
** sorting_functions.c
** File description:
** sorting functions for ls
*/
#include "my_ls.h"

//Strcmp function that ignores cases.
int	my_strcmp_casse(char *s1, char *s2)
{
	int	i = 0;
	char	j;

	while (CASSE(s1[i]) == CASSE(s2[i]) && (s1[i] && s2[i])) {
		++i;
	}
	j = CASSE(s1[i]) - CASSE(s2[i]);
	return (j);
}

//Function to sort by alphabetic order.
int	sort_alpha(void *data, void *data_2)
{
	struct my_ls	*tmp = (struct my_ls *)data;
	struct my_ls	*tmp_2 = (struct my_ls *)data_2;

	if (my_strcmp_casse(tmp->info->d_name, tmp_2->info->d_name) > 0)
		return (1);
	return (0);
}

//Function to sort by size.
int	sort_size(void *data, void *data_2)
{
	struct my_ls	*tmp = (struct my_ls *)data;
	struct my_ls	*tmp_2 = (struct my_ls *)data_2;

	if (tmp->s->st_size < tmp_2->s->st_size)
		return (1);
	return (0);
}

//Function to sort by modification time.
int	sort_time(void *data, void *data_2)
{
	struct my_ls	*tmp = (struct my_ls *)data;
	struct my_ls	*tmp_2 = (struct my_ls *)data_2;

	if (tmp->s->st_mtime < tmp_2->s->st_mtime)
		return (1);
	return (0);
}

//Prints total of blocks allocated.
int	size_blocks(char *path)
{
	DIR		*d = opendir(path);
	struct dirent	*info;
	struct stat	buf;
	int		count = 0;

	while ((info = readdir(d)) != NULL) {
		stat(path, &buf);
		count += buf.st_blocks;
	}
	return (count);
}