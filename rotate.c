#include "push_swap.h"

static void ft_rotate(t_list **stack)
{
	t_list *tmp1;
	t_list *tmp2;

	if (*stack)
	{
		tmp1 = ft_lstlast(*stack);
		tmp2 = *stack;
		tmp1->next = tmp2;
		*stack = tmp2->next;
		tmp2->next = 0;
	}
}

void ft_ra(t_sort *sort)
{
	ft_rotate(&sort->stack_a);
	sort->iteration++;
	ft_lstadd_back(&sort->commands, ft_lstnew(RA));
}

void ft_rb(t_sort *sort)
{
	ft_rotate(&sort->stack_b);
	sort->iteration++;
	ft_lstadd_back(&sort->commands, ft_lstnew(RB));
}

void ft_rr(t_sort *sort)
{
	ft_rotate(&sort->stack_a);
	ft_rotate(&sort->stack_b);
	sort->iteration++;
	ft_lstadd_back(&sort->commands, ft_lstnew(RR));
}
