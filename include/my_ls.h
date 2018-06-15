/*
** EPITECH PROJECT, 2017
** my_ls.h
** File description:
** header file for my_ls
*/
#ifndef MY_LS_H
#define MY_LS_H

#include <pwd.h>
#include <grp.h>
#include <stdbool.h>
#include "my.h"
#include "define.h"
#include "list.h"
#include "error.h"

enum flags {
	L, 
	D,
	T,
	A,
	R,
	REC,
	O,
	S
};

struct options {
	char	*flag;
	int	on;
	void	(*ptr)(struct node *list, char *path);
};

struct my_ls {
	struct stat	*s;
	struct dirent	*info;
	struct passwd	*pwd;
	struct group	*grp;
	char		*str;
	time_t		t;
	bool		display;
};

void	my_ls(char *path, int display_path);
void	print_list(void *data);
void	normal_ls(int ac, char **av);
void	option_big_s(struct node *list, char *path);
void	option_o(struct node *list, char *path);
void	option_l(struct node *list, char *path);
void	option_time(struct node *list, char *path);
void	option_a(struct node *list, char *path);
void	option_d(struct node *list, char *path);
void	option_recursive(struct node *list, char *path);
int	validate_flags(char *str);
int	number_path(int ac, char **av);
int	errors(int ac, char **av);
int	my_strcmp_casse(char *s1, char *s2);
int	size_blocks(char *path);
int	check_flags(char **av, int ac);
int	sort_alpha(void *data, void *data_2);
int	sort_time(void *data, void *data_2);
int	sort_size(void *data, void *data_2);
int	compare_alpha(void *str, void *str_2);
char	*get_path(int ac, char **av);
bool	check_file_arg(int ac, char **av);
DIR	*fill_list(struct node **list, char *path);
struct	options check[NB_OPTIONS];
void	free_ls(void *data);
void	check_rights(struct my_ls *tmp);

#endif