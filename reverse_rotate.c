#include "push_swap.h"

static void ft_reverse_rotate(t_list **stack)
{
	t_list *first;
	t_list *last;
	t_list *penultimate;
	int lstsize;

	lstsize = ft_lstsize(*stack);
	if (*stack)
	{
		first = *stack;
		last = ft_lstlast(*stack);
		penultimate = *stack;
		while (penultimate->next && penultimate->next->next)
			penultimate = penultimate->next;
		penultimate->next = 0;
		if (lstsize > 1)
			last->next = first;
		else
			last->next = 0;
		*stack = last;
	}
}

/**
 * @brief Performs a reverse rotate operation on stack A.
 *
 * @param sort Pointer to the sorting structure containing the stacks.
 */
void ft_rra(t_sort *sort)
{
	ft_reverse_rotate(&sort->stack_a);
	sort->iteration++;
	ft_lstadd_back(&sort->commands, ft_lstnew(RRA));
}

void ft_rrb(t_sort *sort)
{
	ft_reverse_rotate(&sort->stack_b);
	sort->iteration++;
	ft_lstadd_back(&sort->commands, ft_lstnew(RRB));
}

void ft_rrr(t_sort *sort)
{
	ft_reverse_rotate(&sort->stack_a);
	ft_reverse_rotate(&sort->stack_b);
	sort->iteration++;
	ft_lstadd_back(&sort->commands, ft_lstnew(RRR));
}
