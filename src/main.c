#include "../include/push_swap.h"

int	is_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int main(int argc, char **argv)
{
	t_stack  *stack_a;
	t_stack  *stack_b;

	if (argc < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	if(!fill_stack(&stack_a, argv))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	if(!stack_a || !check_param(&stack_a) || !normalise_stack(&stack_a))
	{
		ft_putstr_fd("Error\n", 2);
		free_stack(&stack_a);
		return (0);
	}
	if (!is_sorted(stack_a))
		sort(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}