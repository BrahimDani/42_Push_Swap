#include "../include/push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	// if (!stack && !*stack || !(*stack)->next)
	// 	return ;
	if (*stack && (*stack)->next)
	{
		tmp1 = *stack;
		*stack = (*stack)->next;
		tmp2 = *stack;
		while (tmp2->next)
			tmp2 = tmp2->next;
		tmp2->next = tmp1;
		tmp1->next = NULL;
	}
}

void	rb(t_stack **stack_b)
{
	rotate(stack_b);
	ft_putstr_fd("rb\n", 1);
}

void	ra(t_stack **stack_a)
{
	rotate(stack_a);
	ft_putstr_fd("ra\n", 1);
}

void	rr(t_stack **stack1, t_stack **stack2)
{
	rotate(stack1);
	rotate(stack2);
	ft_putstr_fd("rr\n", 1);
}