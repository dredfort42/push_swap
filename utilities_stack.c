#include "push_swap.h"

t_list	*ft_stack_copy(t_list **stack)
{
	t_list	*p;
	t_list	*stack_copy;

	p = *stack;
	stack_copy = 0;
	while (p)
	{
		ft_lstadd_back(&stack_copy, ft_lstnew(p->number));
		p = p->next;
	}
	return (stack_copy);
}

void	ft_free_stack(t_list *stack)
{
	t_list	*next;

	next = 0;
	while (stack && stack->next)
	{
		next = stack->next;
		free(stack);
		stack = next;
	}
	free(stack);
}

short	ft_is_stack_sorted(t_list *stack)
{
	t_list	*p;

	p = stack;
	while (p->next)
	{
		if (p->number > p->next->number)
			return (0);
		p = p->next;
	}
	return (1);
}

short 	ft_lst_max_order(t_list *lst)
{
	short	max_order;
	t_list	*p;

	max_order = 0;
	p = lst;
	while (p)
	{
		if (p->order > max_order)
			max_order = p->order;
		p = p->next;
	}
	return (max_order);
}

short	ft_lst_min_order(t_list *lst)
{
	short	min_order;
	t_list	*p;

	p = lst;
	min_order = p->order;
	while (p)
	{
		if (p->order < min_order)
			min_order = p->order;
		p = p->next;
	}
	return (min_order);
}
