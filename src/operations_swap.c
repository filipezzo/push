/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsousa <fsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 14:22:46 by fsousa            #+#    #+#             */
/*   Updated: 2025/10/25 16:56:58 by fsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void swap_top(t_stack **s, int should_print, const char *op)
{
	t_stack *first;
	t_stack *second;
	t_stack *third;
	t_stack *last;

	if (!s || !*s || (*s)->next == *s)
		return;
	first = *s;
	second = first->next;
	if (second->next == first)
	{
		*s = second;
		if (should_print)
			ft_putstr_fd((char *)op, 1);
		return;
	}
	third = second->next;
	last = first->prev;
	first->next = third;
	first->prev = second;
	third->prev = first;
	second->next = first;
	second->prev = last;
	last->next = second;
	*s = second;
	if (should_print)
		ft_putstr_fd((char *)op, 1);
}

void sa(t_stack **stack_a, int should_print)
{
	swap_top(stack_a, should_print, "sa\n");
}

void sb(t_stack **stack_b, int should_print)
{
	swap_top(stack_b, should_print, "sb\n");
}

void ss(t_stack **stack_a, t_stack **stack_b)
{
	swap_top(stack_a, 0, "");
	swap_top(stack_b, 0, "");
	ft_putstr_fd("ss\n", 1);
}
