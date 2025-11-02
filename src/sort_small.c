/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsousa <fsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 13:04:56 by fsousa            #+#    #+#             */
/*   Updated: 2025/10/30 13:28:06 by fsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_the_min_node(t_stack *stack)
{
	t_stack	*current;
	t_stack	*min_node;

	if (!stack)
		return (NULL);
	min_node = stack;
	current = stack->next;
	while (current != stack)
	{
		if (current->value < min_node->value)
			min_node = current;
		current = current->next;
	}
	return (min_node);
}

int	get_node_position(t_stack *node, t_stack *min_node)
{
	int		position;
	t_stack	*current;

	if (!node || !min_node)
		return (-1);
	current = node;
	position = 0;
	while (current != min_node)
	{
		current = current->next;
		position++;
	}
	return (position);
}

void	move_min_to_top_a(t_stack **a)
{
	t_stack	*min_node;
	int		size;
	int		position;
	int		i;

	size = ft_stack_size(*a);
	min_node = find_the_min_node(*a);
	position = get_node_position(*a, min_node);
	i = 0;
	if (i <= size / 2)
	{
		while (i < position)
		{
			ra(a, 1);
			i++;
		}
	}
	else
	{
		while (i < (size - position))
		{
			rra(a, 1);
			i++;
		}
	}
}
