#include "../include/push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*tmp;

	// if (stack && *stack && (*stack)->next)
	// 	return ;
	if (*stack && (*stack)->next)
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
	if (stack1 && *stack1 && (*stack1)->next)
		swap(stack1);
	if (stack2 && *stack2 && (*stack2)->next)
		swap(stack2);
	ft_putstr_fd("ss\n", 1);
}
