#include "../include/push_swap.h"

int check_sign(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if ((str[i] == '-' || str[i] == '+') && (!ft_isdigit(str[i + 1])
							|| (i > 0 && str[i - 1] != ' ')))
						return (1);
		i++;
	}
	return (0);
}

int contain_num(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	empty_arg(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_strlen(argv[i]) == 0 || !contain_num(argv[i]))
			return (1);
		if (check_sign(argv[i]))
			return (1);
		i++;
	}
	return (0);
}