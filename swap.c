#include "push_swap.h"

static void ft_swap(t_list **stack)
{
	t_list *tmp1;
	t_list *tmp2;

	if (*stack)
	{
		tmp1 = *stack;
		tmp2 = tmp1->next;
		tmp1->next = tmp2->next;
		tmp2->next = tmp1;
		*stack = tmp2;
	}
}

void ft_sa(t_sort *sort)
{
	ft_swap(&sort->stack_a);
	sort->iteration++;
	ft_lstadd_back(&sort->commands, ft_lstnew(SA));
}

void ft_sb(t_sort *sort)
{
	ft_swap(&sort->stack_b);
	sort->iteration++;
	ft_lstadd_back(&sort->commands, ft_lstnew(SB));
}

void ft_ss(t_sort *sort)
{
	ft_swap(&sort->stack_a);
	ft_swap(&sort->stack_b);
	sort->iteration++;
	ft_lstadd_back(&sort->commands, ft_lstnew(SS));
}
