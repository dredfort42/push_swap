#include "push_swap.h"

static void	ft_push(t_list **take, t_list **put)
{
	t_list	*tmp;

	if (*take)
	{
		tmp = *take;
		*take = tmp->next;
		if (*put && ft_lstsize(*put))
			tmp->next = *put;
		else
			tmp->next = 0;
		*put = tmp;
	}
}

void	ft_pa(t_sort *sort)
{
	ft_push(&sort->stack_b, &sort->stack_a);
	sort->iteration++;
	ft_lstadd_back(&sort->commands, ft_lstnew(4));
}

void	ft_pb(t_sort *sort)
{
	ft_push(&sort->stack_a, &sort->stack_b);
	sort->iteration++;
	ft_lstadd_back(&sort->commands, ft_lstnew(5));
}
