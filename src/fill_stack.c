#include "../include/push_swap.h"

long long int	ft_atoll(const char *str)
{
	int				negative;
	int				i;
	long long int	nb;

	i = 0;
	negative = 1;
	nb = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			negative = negative * -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	return (nb * negative);
}

void	add_stack(t_stack **stack, size_t value)
{
	t_stack	*new;
	t_stack	*tmp;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return;
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

/*
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
*/


int	fill_stack_tabs(t_stack **stack, char *ptr)
{
	char	**tab;
	long	n;
	int		i;
	int		j;

	tab = ft_split(ptr, ' ');
	i = -1;
	while(tab[++i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (ft_isalpha(tab[i][j]))
				return (free(ptr), free_tab(tab), 0);
			j++;
		}
		n = ft_atoll(tab[i]);
		if (n > INT_MAX || n < INT_MIN)
			return (free(ptr),free_tab(tab), 0);
		add_stack(stack, n);
	}
	return (free(ptr), free_tab(tab), 1);
}


int fill_stack(t_stack **stack, char **argv)
{
	int      i;
	char    *ptr;

	ptr = NULL;
	i = 1;
	//if (empty_arg(argv))
	//	return (0);
	while (argv[i])
	{
		if(!ptr)
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