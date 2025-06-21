/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brdani <brdani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 00:13:28 by brdani            #+#    #+#             */
/*   Updated: 2025/06/20 00:32:36 by brdani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	max_value;
	int	max_bits;
	int	i;
	int	j;

	max_value = get_stacksize(*stack_a) - 1;
	max_bits = 0;
	while (max_value >> max_bits)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < max_value + 1)
		{
			if (((*stack_a)->value >> i) & 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			j++;
		}
		while (*stack_b)
			pa(stack_a, stack_b);
		i++;
	}
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	int	min;
	int	max;

	if (get_stacksize(*stack_a) <= 1)
		return ;
	else if (get_stacksize(*stack_a) == 2)
		sa(stack_a);
	else if (get_stacksize(*stack_a) == 3)
		sort_by_3(stack_a);
	else if (get_stacksize(*stack_a) == 4)
		sort_by_4(stack_a, stack_b);
	else if (get_stacksize(*stack_a) == 5)
		sort_by_5(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}
