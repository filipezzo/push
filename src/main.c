/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsousa <fsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:33:47 by fsousa            #+#    #+#             */
/*   Updated: 2025/10/28 16:36:57 by fsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char *argv[])
{
	t_stack *stack_a;
	t_stack *stack_b;

	if (argc < 2)
		return (1);
	stack_a = NULL;
	stack_b = NULL;

	ft_parse_and_fill(&stack_a, &stack_b, argc, argv);
	sort_stack(&stack_a, &stack_b);
	ft_printf("STACK A DAQUELE JEITO!!\n");
	ft_print_stack(stack_a);
	return (0);
}
