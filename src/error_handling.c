/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsousa <fsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:29:42 by fsousa            #+#    #+#             */
/*   Updated: 2025/10/24 18:38:32 by fsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_has_duplicates(t_stack *head)
{
	t_stack	*current;
	t_stack	*runner;

	if (!head || head->next == head)
		return (0);
	current = head;
	while (current->next != head)
	{
		runner = current->next;
		while (runner != head)
		{
			if (current->value == runner->value)
				return (1);
			runner = runner->next;
		}
		current = current->next;
	}
	return (0);
}

void	ft_exit_error(t_stack **stack_a, t_stack **stack_b, char **split_array)
{
	if (split_array)
		ft_free_arr(split_array);
	if (stack_a)
		ft_free_stack(stack_a);
	if (stack_b)
		ft_free_stack(stack_b);
	write(2, "Error\n", 6);
	exit(1);
}
