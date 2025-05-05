#include "../include/push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*tmp;

	if(*stack && (*stack)->next)
	{
		tmp = (*stack)->next;
		(*stack)->next = tmp->next;
		tmp->next = *stack;
		*stack = tmp;
	}
}

void	sa(t_stack **stack_a)
{
	swap(stack_a);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack **stack_b)
{
	swap(stack_b);
	ft_putstr_fd("sb\n", 1);
}

void	swap_both(t_stack **stack1, t_stack **stack2)
{
	swap(stack1);
	swap(stack2);
	ft_putstr_fd("ss\n", 1);
}
