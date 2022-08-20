#include "push_swap.h"

void	ft_5_sort(t_sort *sort)
{
	while (ft_lstsize(sort->stack_b) != 2)
	{
		if (sort->stack_a->order > 2)
			ft_ra(sort);
		else
			ft_pb(sort);
	}
	ft_3_sort(sort);
	if (sort->stack_b->order == 1)
		ft_rb(sort);
	ft_pa(sort);
	ft_pa(sort);
}
