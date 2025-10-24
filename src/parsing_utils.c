/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsousa <fsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:38:28 by fsousa            #+#    #+#             */
/*   Updated: 2025/10/24 18:42:16 by fsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_which_exit_error(int argc, t_stack **a, t_stack **b,
		char **args_array)
{
	if (argc == 2)
		ft_exit_error(a, b, args_array);
	else
		ft_exit_error(a, b, NULL);
}

static char	**ft_initialize_num(int argc, char **argv, t_stack **a, t_stack **b)
{
	char	**args_array;

	args_array = NULL;
	if (argc == 2)
	{
		args_array = ft_split(argv[1], ' ');
		if (!args_array)
			ft_exit_error(a, b, NULL);
	}
	else if (argc > 2)
		args_array = &argv[1];
	return (args_array);
}

void	ft_parse_and_fill(t_stack **stack_a, t_stack **stack_b, int argc,
		char **argv)
{
	char	**args_array;
	int		i;
	int		error_flag;
	int		num;
	t_stack	*new_node;

	i = 0;
	error_flag = 0;
	args_array = ft_initialize_num(argc, argv, stack_a, stack_b);
	while (args_array[i])
	{
		num = ft_robust_atoi(args_array[i], &error_flag);
		if (error_flag == 1)
			ft_which_exit_error(argc, stack_a, stack_b, args_array);
		new_node = ft_new_node(num);
		if (!new_node)
			ft_which_exit_error(argc, stack_a, stack_b, args_array);
		ft_add_node_back(stack_a, new_node);
		i++;
	}
	if (argc == 2)
		ft_free_arr(args_array);
	if (ft_has_duplicates(*stack_a))
		ft_exit_error(stack_a, stack_b, NULL);
}
