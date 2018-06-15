/*
** EPITECH PROJECT, 2017
** create_list.c
** File description:
** circular doubly linked list
*/
#include "list.h"

//Inserts at the beginning.
static	int insert_begin(struct node **head, void *data)
{
	struct node	*new_node = malloc(sizeof(struct node));

	if (new_node == NULL)
		return (84);
	new_node->next = new_node->prev = new_node;
	new_node->data = data;
	*head = new_node;
	return (0); 
}

//Inserts at the end.
int	insert_end(struct node **head, void *data)
{
	struct node	*new_node = malloc(sizeof(struct node));
	struct node	*last;

	if (new_node == NULL)
		return (84);
	if (*head == NULL)
		insert_begin(head, data);
	else {
		last = (*head)->prev;
		new_node->next = *head;
		(*head)->prev = new_node;
		new_node->prev = last;
		last->next = new_node;
		new_node->data = data;
	}
	return (0);
}