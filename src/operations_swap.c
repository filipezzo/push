/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsousa <fsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 14:22:46 by fsousa            #+#    #+#             */
/*   Updated: 2025/10/30 11:12:15 by fsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_top(t_stack **s)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;
	t_stack	*last;

	if (!s || !*s || (*s)->next == *s)
		return ;
	first = *s;
	second = first->next;
	if (second->next == first)
	{
		*s = second;
		return ;
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
}

void	sa(t_stack **stack_a, int should_print)
{
	swap_top(stack_a);
	if (should_print)
		ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack **stack_b, int should_print)
{
	swap_top(stack_b);
	if (should_print)
		ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap_top(stack_a);
	swap_top(stack_b);
	ft_putstr_fd("ss\n", 1);
}
