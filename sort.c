#include "push_swap.h"

static void	ft_sort_basic(t_sort *sort)
{
	while (sort->stack_b)
		ft_sort_b(sort);
	while (!ft_is_stack_sorted(sort->stack_a))
	{
		ft_sort_a(sort);
		while (sort->stack_b)
			ft_sort_b(sort);
	}
}

static void	ft_sort_small(t_list **stack, t_sort *sort)
{
	short	mid_reduce;
	t_list	*stack_copy;

	mid_reduce = 0;
	sort->iteration = 700;
	while (sort->iteration > 699)
	{
		ft_free_stack(sort->commands);
		stack_copy = ft_stack_copy(stack);
		ft_reset_sort(sort);
		sort->stack_a = stack_copy;
		ft_determine_order(sort);
		ft_presort_a(sort, mid_reduce);
		ft_sort_basic(sort);
		mid_reduce++;
		ft_free_stack(sort->stack_a);
	}
}

static void	ft_sort_large(t_sort *sort)
{
	ft_presort_a(sort, 0);
	ft_sort_basic(sort);
	ft_free_stack(sort->stack_a);
}

void	ft_sort(t_list **stack)
{
	t_sort	sort;

	ft_reset_sort(&sort);
	sort.stack_a = *stack;
	ft_determine_order(&sort);
	if (ft_lstsize(sort.stack_a) == 3)
	{
		ft_3_sort(&sort);
		ft_free_stack(sort.stack_a);
	}
	else if (ft_lstsize(sort.stack_a) == 5)
	{
		ft_5_sort(&sort);
		ft_free_stack(sort.stack_a);
	}
	else if (ft_lstsize(sort.stack_a) <= 100)
		ft_sort_small(stack, &sort);
	else
		ft_sort_large(&sort);
	ft_print_commands(&sort);
}
