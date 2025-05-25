#include "../include/push_swap.h"

void    reverse_rotate(t_stack **stack)
{
    t_stack *tmp1;
    t_stack *tmp2;

    if (!stack || !*stack || !(*stack)->next)
        return ;
    if (*stack && (*stack)->next)
    {
        tmp1 = *stack;
        while (tmp1->next->next)
            tmp1 = tmp1->next;
        tmp2 = tmp1->next;
        tmp1->next = NULL;
        tmp2->next = *stack;
        *stack = tmp2;
    }
}

void    rra(t_stack **stack_a)
{
    reverse_rotate(stack_a);
    ft_putstr_fd("rra\n", 1);
}

void    rrb(t_stack **stack_b)
{
    reverse_rotate(stack_b);
    ft_putstr_fd("rrb\n", 1);
}

void    rrr(t_stack **stack1, t_stack **stack2)
{
    reverse_rotate(stack1);
    reverse_rotate(stack2);
    ft_putstr_fd("rrr\n", 1);
}