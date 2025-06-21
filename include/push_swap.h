#ifndef	PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>

typedef struct s_stack
{
	int 			size;
	int				value;
	struct s_stack	*next;
	
}	t_stack;

int				check_param(t_stack **stack);
void			add_stack(t_stack **stack, size_t value);
char			*ft_join_free(char *stash, char *buffer);
int				fill_stack_tabs(t_stack **stack, char *ptr);
int				fill_stack(t_stack **stack, char **argv);
int				normalise_stack(t_stack **stack);
int				*stack_copy(t_stack *stack);
int				*sort_tab(int *tab, int size);
long long int	ft_atoll(const char *str);
void			free_tab(char **tab);
int				stacksize(t_stack *stack);
int				is_sorted(t_stack *stack);
void			find_min_max(t_stack *stack_a, int *min, int *max, int *index);
void			sort_by_3(t_stack **stack_a);
void			sort_by_4(t_stack **stack_a, t_stack **stack_b);
void			sort_by_5(t_stack **stack_a, t_stack **stack_b);
void			radix_sort(t_stack **stack_a, t_stack **stack_b);
void			sort(t_stack **stack_a, t_stack **stack_b);
void			push(t_stack **stack1, t_stack **stack2);
void			pa(t_stack **stack_a, t_stack **stack_b);
void			pb(t_stack **stack_a, t_stack **stack_b);
void			reverse_rotate(t_stack **stack);
void			rra(t_stack **stack_a);
void			rrb(t_stack **stack_b);
void			rrr(t_stack **stack1, t_stack **stack2);
void			rotate(t_stack **stack);
void			rb(t_stack **stack_b);
void			ra(t_stack **stack_a);
void			rr(t_stack **stack1, t_stack **stack2);
void			swap(t_stack **stack);
void			sa(t_stack **stack_a);
void			sb(t_stack **stack_b);
void			swap_both(t_stack **stack1, t_stack **stack2);
void			free_stack(t_stack **stack);
int				get_stacksize(t_stack *stack);
int				empty_arg(char **argv);
int				contain_alpha(char *str);
t_stack			*new_stack(int value);

#endif