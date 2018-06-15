/*
** EPITECH PROJECT, 2017
** my_str_to_word_array.c
** File description:
** str to array
*/
#include "my.h"

int	is_alphanum(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
	(c >= '0' && c <= '9'))
		return (1);
	return (0);
}

void	*my_malloc(int size)
{
	void	*str;

	if ((str = malloc(size)) == NULL)
		return (NULL);
	return (str);
}

static int my_count(char const *str, int i)
{
	int	count = 0;

	while (is_alphanum(str[i]) == 1) {
			++count;
			++i;
		}
	return (count);
}

char	**my_str_to_word_array(char const *str)
{
	char	**tab;
	int	i = 0;
	int	j = 0;
	int	count;

	tab = my_malloc(sizeof(char *) * (10000 + 1));
	while (str[i]) {
		while (str[i] && is_alphanum(str[i]) == 0)
			++i;
		if (!str[i])
			break;
		count = 0;
		tab[j] = my_malloc(50000 + 1);
		while (is_alphanum(str[i]) == 1)
			tab[j][count++] = str[i++];
		tab[j++][count] = '\0';
	}
	tab[j] = NULL;
	return (tab);
}