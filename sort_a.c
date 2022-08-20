#include "push_swap.h"

void	ft_quick_sort_a(t_sort *sort)
{
	while (sort->stack_a->order == sort->min
		|| (sort->stack_a->next && sort->stack_a->next->order == sort->min))
	{
		if (sort->stack_a->next && sort->stack_a->next->order == sort->min)
			ft_sa(sort);
		ft_ra(sort);
		sort->min++;
	}
}

void	ft_presort_a(t_sort *sort, short mid_reduce)
{
	int	stack_len;
	int	i;

	i = 0;
	stack_len = ft_lstsize(sort->stack_a);
	sort->max = ft_lst_max_order(sort->stack_a);
	sort->mid = (sort->max + sort->min) / 2 + mid_reduce;
	while (i < stack_len)
	{
		if (sort->stack_a->order > sort->mid)
			ft_ra(sort);
		else
			ft_presort_b(sort);
		i++;
	}
	while (sort->stack_b->order != 1)
		ft_rrb(sort);
	while (sort->stack_b && sort->stack_b->order < sort->min)
	{
		ft_pa(sort);
		ft_ra(sort);
	}
}

void	ft_sort_a(t_sort *sort)
{
	int		stack_len;
	int		i;
	short	processed_num;

	i = 0;
	stack_len = ft_lstsize(sort->stack_a);
	sort->max = ft_lst_max_order(sort->stack_a);
	sort->mid = (sort->max + sort->min) / 2;
	processed_num = sort->stack_a->processed;
	ft_quick_sort_a(sort);
	while (i < stack_len && sort->stack_a->processed == processed_num)
	{
		if (sort->stack_a->order == sort->min
			|| sort->stack_a->next->order == sort->min)
			ft_quick_sort_a(sort);
		else
			ft_pb(sort);
		i++;
	}
}
