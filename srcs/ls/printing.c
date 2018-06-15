/*
** EPITECH PROJECT, 2017
** printing.c
** File description:
** printing functions
*/
#include "my_ls.h"

//Function to print sticky bit and char device.
static	void sticky_bit(struct my_ls *tmp)
{
	if (tmp->s->st_mode & S_ISVTX && !(tmp->s->st_mode & S_IXUSR
	&& tmp->s->st_mode & S_IWGRP))
		my_printf("T");
	else if (tmp->s->st_mode & S_ISVTX)
		my_printf("t");
	else
		my_printf((tmp->s->st_mode & S_IXOTH) ? "x" : "-");
}

//Function to print rights on a file / directory.
static	void print_rights(struct my_ls *tmp)
{
	check_rights(tmp);
	my_printf((tmp->s->st_mode & S_IRUSR) ? "r" : "-");
	my_printf((tmp->s->st_mode & S_IWUSR) ? "w" : "-");
	my_printf((tmp->s->st_mode & S_IXUSR) ? "x" : "-");
	my_printf((tmp->s->st_mode & S_IRGRP) ? "r" : "-");
	my_printf((tmp->s->st_mode & S_IWGRP) ? "w" : "-");
	my_printf((tmp->s->st_mode & S_IXGRP) ? "x" : "-");
	my_printf((tmp->s->st_mode & S_IROTH) ? "r" : "-");
	my_printf((tmp->s->st_mode & S_IWOTH) ? "w" : "-");
	sticky_bit(tmp);
}

//Prints colors
static	void print_color(struct my_ls *tmp)
{
	if (tmp->info->d_type == DT_DIR)
		my_printf("%s%s%s\n", BLUE, tmp->info->d_name, NORMAL_COLOR);
	else if (tmp->info->d_type != DT_DIR && (tmp->s->st_mode & S_IXUSR ||
		tmp->s->st_mode & S_IXGRP || tmp->s->st_mode & S_IXOTH))
			my_printf("%s%s%s\n", GREEN,
			tmp->info->d_name, NORMAL_COLOR);
	else
		my_printf("%s%s\n", NORMAL_COLOR, tmp->info->d_name);
}

//Prints for -l
static void list_files(struct my_ls *data)
{
	char	*str;

	str = ctime(&(data->s->st_mtime));
	data->str = str + 4;
	data->str[12] = '\0';
	print_rights(data);
	my_printf(". %d ", data->s->st_nlink);
	my_printf("%s ", data->pwd->pw_name);
	if (check[O].on == 0)
		my_printf("%s  ", data->grp->gr_name);
	my_printf("%d ", data->s->st_size);
	my_printf("%s ", data->str);
	print_color(data);
}

//Prints the content of the list.
void	print_list(void *data)
{
	struct my_ls	*tmp = (struct my_ls *) data;

	if (tmp->display == true) {
		if (check[L].on == 1 || check[O].on == 1)
			list_files(tmp);
		else
			print_color(tmp);
	}
}