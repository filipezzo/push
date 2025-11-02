/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsousa <fsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 11:12:32 by fsousa            #+#    #+#             */
/*   Updated: 2025/11/02 18:33:47 by fsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_stack	*head;
	t_stack	*current;

	if (!stack || stack->next == stack)
		return (1);
	head = stack;
	current = stack;
	while (current->next != head)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	if (!(*stack_a))
		return ;
	size = ft_stack_size(*stack_a);
	if (is_sorted(*stack_a))
		return ;
	if (size == 2)
		sort_two(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else if (size <= 5)
		sort_five(stack_a, stack_b);
	else
	{
		assign_index(*stack_a);
		radix_sort(stack_a, stack_b);
	}
}
