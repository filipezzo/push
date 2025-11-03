/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsousa <fsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 17:30:18 by fsousa            #+#    #+#             */
/*   Updated: 2025/11/03 16:06:13 by fsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(int max_index)
{
	int	max_bits;

	max_bits = 0;
	while ((max_index >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_stack **a, t_stack **b, int i, int j)
{
	int		size;
	int		max_index;
	int		max_bits;
	t_stack	*top_node;

	size = ft_stack_size(*a);
	max_index = size - 1;
	max_bits = get_max_bits(max_index);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			top_node = *a;
			if (((top_node->index >> i) & 1) == 0)
				pb(a, b, 1);
			else
				ra(a, 1);
			j++;
		}
		while (*b)
			pa(a, b, 1);
		i++;
	}
}
