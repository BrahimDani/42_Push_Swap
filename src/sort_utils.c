/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brdani <brdani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 00:13:22 by brdani            #+#    #+#             */
/*   Updated: 2025/06/20 00:46:01 by brdani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	find_min_max(t_stack *stack_a, int *min, int *max, int *index)
{
	int count;
	*min = stack_a->value;
	*max = stack_a->value;
	count = 0;
	while (stack_a)
	{
		if (stack_a->value < *min)
		{
			*min = stack_a->value;
			*index = count;
		}
		else if (stack_a->value > *max)
			*max = stack_a->value;
		stack_a = stack_a->next;
		count++;
	}
}

void	sort_by_5(t_stack **stack_a, t_stack **stack_b)
{
	int	min;
	int	max;
	int	count;

	while (get_stacksize(*stack_a) > 3)
	{
		find_min_max(*stack_a, &min, &max, &count);
		while ((*stack_a)->value != min)
		{
			if (count <= get_stacksize(*stack_a) / 2)
				ra(stack_a);
			else
				rra(stack_a);
		}
		pb(stack_a, stack_b);
	}
	sort_by_3(stack_a);
	if ((*stack_a) && (*stack_b)->next && \
(*stack_b)->value < (*stack_b)->next->value)
		sb(stack_b);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	sort_by_4(t_stack **stack_a, t_stack **stack_b)
{
	int	min;
	int	max;
	int	count;

	find_min_max(*stack_a, &min, &max, &count);
	while ((*stack_a)->value != min)
		ra(stack_a);
	pb(stack_a, stack_b);
	sort_by_3(stack_a);
	pa(stack_a, stack_b);
}

void	sort_by_3(t_stack **stack_a)
{
	int	min;
	int	max;
	int	count;

	while (!is_sorted(*stack_a))
	{
		find_min_max(*stack_a, &min, &max, &count);
		if ((*stack_a)->value == max)
		{
			ra(stack_a);
			if (!is_sorted(*stack_a))
				sa(stack_a);
		}
		else if ((*stack_a)->value == min)
			ra(stack_a);
		else
			sa(stack_a);
	}
}
