#include "push_swap.h"

void	ft_presort_b(t_sort *sort)
{
	ft_pb(sort);
	sort->stack_b->processed++;
	while (sort->stack_b->order == sort->min && ft_lstsize(sort->stack_b) > 1)
	{
		ft_rb(sort);
		sort->min++;
	}
}

void	ft_sort_b(t_sort *sort)
{
	int	stack_len;
	int	i;

	i = 0;
	stack_len = ft_lstsize(sort->stack_b);
	sort->max = ft_lst_max_order(sort->stack_b);
	sort->mid = (sort->max + sort->min) / 2;
	sort->processed++;
	while (sort->stack_b && i < stack_len)
	{
		sort->stack_b->processed = sort->processed;
		if (sort->stack_b->order == sort->min)
		{
			ft_pa(sort);
			ft_ra(sort);
			sort->min++;
		}
		else if (sort->stack_b->order < sort->mid)
			ft_rb(sort);
		else
			ft_pa(sort);
		ft_quick_sort_a(sort);
		i++;
	}
}
