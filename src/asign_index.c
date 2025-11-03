/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asign_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsousa <fsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 16:09:26 by fsousa            #+#    #+#             */
/*   Updated: 2025/11/03 15:59:26 by fsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*find_first_unindexed_node(t_stack *head)
{
	t_stack	*current;

	if (!head)
		return (NULL);
	current = head;
	while (current)
	{
		if (current->index == -1)
			return (current);
		current = current->next;
		if (current == head)
			return (NULL);
	}
	return (NULL);
}

static t_stack	*find_next_min_node(t_stack *head)
{
	t_stack	*min_node;
	t_stack	*current;

	min_node = find_first_unindexed_node(head);
	if (min_node == NULL)
		return (NULL);
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
