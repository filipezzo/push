/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsousa <fsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 11:13:35 by fsousa            #+#    #+#             */
/*   Updated: 2025/10/30 13:28:49 by fsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack **a)
{
	if ((*a)->value > (*a)->next->value)
		sa(a, 1);
}

void	sort_three(t_stack **a)
{
	t_stack	*first_node;
	t_stack	*second_node;
	t_stack	*third_node;

	first_node = *a;
	second_node = first_node->next;
	third_node = first_node->prev;
	if (first_node->value > second_node->value
		&& first_node->value > third_node->value)
		ra(a, 1);
	else if (second_node->value > first_node->value
		&& second_node->value > third_node->value)
		rra(a, 1);
	if ((*a)->value > (*a)->next->value)
		sa(a, 1);
}

void	sort_five(t_stack **a, t_stack **b)
{
	int	size;

	size = ft_stack_size(*a);
	while (size > 3)
	{
		move_min_to_top_a(a);
		pb(a, b, 1);
		size--;
	}
	sort_three(a);
	while (*b)
		pa(a, b, 1);
}
