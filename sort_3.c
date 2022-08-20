#include "push_swap.h"

static void	ft_sa_rra(t_sort *sort)
{
	ft_sa(sort);
	ft_rra(sort);
}

static void	ft_rra_sa(t_sort *sort)
{
	ft_rra(sort);
	ft_sa(sort);
}

static void	ft_rra_rra(t_sort *sort)
{
	ft_rra(sort);
	ft_rra(sort);
}

void	ft_3_sort(t_sort *sort)
{
	short	min;
	short	max;
	short	mid;

	min = ft_lst_min_order(sort->stack_a);
	max = ft_lst_max_order(sort->stack_a);
	mid = (max + min) / 2;
	if (!ft_is_stack_sorted(sort->stack_a))
	{
		if (sort->stack_a->order == mid
			&& ft_lstlast(sort->stack_a)->order == min)
			ft_rra(sort);
		else if (sort->stack_a->order == mid)
			ft_sa(sort);
		else if (sort->stack_a->next->order == mid)
			ft_sa_rra(sort);
		else if (sort->stack_a->order == min
			&& ft_lstlast(sort->stack_a)->order == mid)
			ft_rra_sa(sort);
		else
			ft_rra_rra(sort);
	}
}
