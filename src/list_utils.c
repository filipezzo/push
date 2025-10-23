/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsousa <fsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 12:59:08 by fsousa            #+#    #+#             */
/*   Updated: 2025/10/23 15:29:06 by fsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_new_node(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = -1;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

void	ft_add_node_back(t_stack **head, t_stack *new_node)
{
	t_stack *last_node;

	if (!new_node)
		return ;
	if (!*head)
	{
		*head = new_node;
		new_node->next = new_node;
		new_node->prev = new_node;
		return ;
	}
	last_node = (*head)->prev;
	new_node->next = *head;
	new_node->prev = last_node;
	last_node->next = new_node;
	(*head)->prev = new_node;
}

int     ft_stack_size(t_stack *head)
{
	int size;
	t_stack *current;
	
	if(!head)
		return (0);
	if(head->next == head)
		return (1);
	current = head->next;
	size = 1;
	while(current != head)
	{
		current = current->next;
		size++;
	}
	return (size);
}

void    ft_free_stack(t_stack **head)
{
	t_stack *current;
	t_stack *temp;
	t_stack *tail;

	if(!head || !*head)
		return; 
	current = *head;
	tail = (*head)->prev;
	tail->next = NULL;
	while(current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	*head = NULL;
}