/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsousa <fsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:30:20 by fsousa            #+#    #+#             */
/*   Updated: 2025/10/23 17:28:44 by fsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_stack(t_stack *stack)
{
	t_stack *current;

	if(!stack)
		return ;
	if(stack->next == stack)
	{
		ft_printf("%d\n", stack->value);
		return ;
	}
	current = stack;
	ft_printf("%d\n", current->value);
	current = stack->next;
	while(current != stack)
	{
		ft_printf("%d\n", current->value);
		current = current->next;
	}
}

