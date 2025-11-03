/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsousa <fsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 11:03:33 by fsousa            #+#    #+#             */
/*   Updated: 2025/11/03 13:37:09 by fsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*pop_from_stack(t_stack **head)
{
	t_stack	*node_to_pop;
	t_stack	*prev_node;
	t_stack	*next_node;

	if (!head || !(*head))
		return (NULL);
	node_to_pop = *head;
	if (node_to_pop->next == node_to_pop)
		*head = NULL;
	else
	{
		next_node = node_to_pop->next;
		prev_node = node_to_pop->prev;
		next_node->prev = prev_node;
		prev_node->next = next_node;
		*head = next_node;
	}
	node_to_pop->next = NULL;
	node_to_pop->prev = NULL;
	return (node_to_pop);
}

static void	push_to_stack(t_stack **head, t_stack *node_to_push)
{
	t_stack	*last_node;

	if (!node_to_push)
		return ;
	if (!(*head))
	{
		*head = node_to_push;
		node_to_push->next = node_to_push;
		node_to_push->prev = node_to_push;
		return ;
	}
	last_node = (*head)->prev;
	node_to_push->next = *head;
	node_to_push->prev = last_node;
	last_node->next = node_to_push;
	(*head)->prev = node_to_push;
	*head = node_to_push;
}

void	pa(t_stack **stack_a, t_stack **stack_b, int should_print)
{
	t_stack	*node_to_move;

	node_to_move = pop_from_stack(stack_b);
	if (!node_to_move)
		return ;
	push_to_stack(stack_a, node_to_move);
	if (should_print)
		ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack **stack_a, t_stack **stack_b, int should_print)
{
	t_stack	*node_to_move;

	node_to_move = pop_from_stack(stack_a);
	if (!node_to_move)
		return ;
	push_to_stack(stack_b, node_to_move);
	if (should_print)
		ft_putstr_fd("pb\n", 1);
}
