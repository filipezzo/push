/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsousa <fsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 12:59:10 by fsousa            #+#    #+#             */
/*   Updated: 2025/10/28 16:36:47 by fsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define MAX_INT 2147483647
# define MIN_INT -2147483648
# include "../lib/libft/include/libft.h"
# include <stdlib.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

t_stack				*ft_new_node(int value);
void				ft_add_node_back(t_stack **head, t_stack *new_node);
int					ft_stack_size(t_stack *head);
void				ft_free_stack(t_stack **head);

void				ft_parse_and_fill(t_stack **stack_a, t_stack **stack_b,
						int argc, char **argv);
void				ft_exit_error(t_stack **a, t_stack **b, char **split_array);
int					ft_has_duplicates(t_stack *head);
void				ft_exit_error(t_stack **stack_a, t_stack **stack_b,
						char **split_array);

void				ft_print_stack(t_stack *stack);

void				ft_free_arr(char **arr);
int					ft_robust_atoi(const char *str, int *error_flag);
void				sa(t_stack **stack_a, int should_print);
void				sb(t_stack **stack_b, int should_print);
void				ss(t_stack **stack_a, t_stack **stack_b);
void				ra(t_stack **stack_a, int should_print);
void				rb(t_stack **stack_b, int should_print);
void				rr(t_stack **stack_a, t_stack **stack_b);
void				rra(t_stack **stack_a, int should_print);
void				rrb(t_stack **stack_b, int should_print);
void				rrr(t_stack **stack_a, t_stack **stack_b);
void				pa(t_stack **stack_a, t_stack **stack_b, int should_print);
void				pb(t_stack **stack_a, t_stack **stack_b, int should_print);
#endif