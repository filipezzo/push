/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asign_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsousa <fsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 16:09:26 by fsousa            #+#    #+#             */
/*   Updated: 2025/11/02 17:47:44 by fsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*find_next_min_node(t_stack *head)
{
	t_stack	*current;
	t_stack	*min_node;

	current = head;
	min_node = NULL;
	while (current)
	{
		if (current->index == -1)
		{
			min_node = current;
			break ;
		}
		current = current->next;
		if (current == head)
			return (NULL);
	}
	current = head;
	while (current)
	{
		if (current->index == -1 && current->value < min_node->value)
			min_node = current;
		current = current->next;
		if (current == head)
			break ;
	}
	return (min_node);
}

void	assign_index(t_stack *head)
{
	int		size;
	int		current_index;
	t_stack	*node_to_index;

	if (!head)
		return ;
	size = ft_stack_size(head);
	current_index = 0;
	while (current_index < size)
	{
		node_to_index = find_next_min_node(head);
		if (node_to_index)
			node_to_index->index = current_index;
		current_index++;
	}
}
