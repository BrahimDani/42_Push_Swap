#include "../include/push_swap.h"

int	*sort_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size)
	{
		j = i;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (tab);
}

int	*stack_copy(t_stack *stack)
{
	int	*copy;
	int	i;

	i = 0;
	copy = malloc(sizeof(int) * stacksize(stack));
	if(!copy)
	{
		ft_putstr_fd("Error\n", 1);
		return (NULL);
	}
	while (stack)
	{
		copy[i] = stack->value;
		stack = stack->next;
		i++;
	}
	return (copy);
}

int	normalise_stack(t_stack **stack)
{
	t_stack	*tmp;
	int		*copy;
	int		j;

	tmp = *stack;
	copy = stack_copy(tmp);
	if (!copy)
		return (0);
	copy = sort_tab(copy, stacksize(*stack));
	while (tmp)
	{
		j = 0;
		while (j < stacksize(*stack))
		{
			if (tmp->value == copy[j])
			{
				tmp->value = j;
				break ;
			}
			j++;
		}
		tmp = tmp->next;
	}
	free(copy);
	return (1);
}
