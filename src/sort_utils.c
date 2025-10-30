#include "push_swap.h"

int is_sorted(t_stack *stack)
{
    t_stack *head;
    t_stack *current;

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

void sort_stack(t_stack **stack_a, t_stack **stack_b)
{
    int size;

    (void)stack_b;
    if (!(*stack_a))
        return;
    size = ft_stack_size(*stack_a);
    if (is_sorted(*stack_a))
        return;
    if (size == 2)
        sort_two(stack_a);
    else if (size == 3)
        sort_three(stack_a);
    // else if (size <= 5)
    //     sort_five(stack_a, stack_b);
    // else
    // {
    //     assign_index(*stack_a);
    //     radix_sort(stack_a, stack_b); 5
    // }
}