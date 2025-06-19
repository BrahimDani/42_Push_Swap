/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brdani <brdani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 00:13:04 by brdani            #+#    #+#             */
/*   Updated: 2025/06/20 00:26:20 by brdani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	add_stack(t_stack **stack, size_t value)
{
	t_stack	*new;
	t_stack	*tmp;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return ;
	new->value = value;
	new->next = NULL;
	if (!*stack)
		*stack = new;
	else
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

char	*ft_join_free(char *s1, char *s2)
{
	char	*str;
	char	*tmp;

	str = ft_strjoin(s1, " ");
	tmp = str;
	str = ft_strjoin(str, s2);
	free(s1);
	free(tmp);
	return (str);
}

int	contain_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isalpha(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	fill_stack_tabs(t_stack **stack, char *ptr)
{
	int		i;
	char	**tab;

	i = 0;
	tab = ft_split(ptr, ' ');
	while (tab[i])
	{
		if (ft_atoll(tab[i]) > INT_MAX || ft_atoll(tab[i])
			< INT_MIN || contain_alpha(tab[i]))
		{
			free(ptr);
			free_tab(tab);
			return (0);
		}
		add_stack(stack, ft_atoll(tab[i]));
		i++;
	}
	free(ptr);
	free_tab(tab);
	return (1);
}

int	fill_stack(t_stack **stack, char **argv)
{
	int		i;
	char	*ptr;

	ptr = NULL;
	i = 1;
	if (empty_arg(argv))
		return (0);
	while (argv[i])
	{
		if (!ptr)
		{
			ptr = malloc(sizeof(char) * (ft_strlen(argv[i]) + 1));
			ft_strlcpy(ptr, argv[i], ft_strlen(argv[i]) + 1);
		}
		else
			ptr = ft_join_free(ptr, argv[i]);
		i++;
	}
	if (!fill_stack_tabs(stack, ptr))
		return (0);
	return (1);
}
