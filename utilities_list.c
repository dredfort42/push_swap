#include "push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*p;

	p = malloc(sizeof(t_list));
	if (!p)
		return (0);
	p->next = 0;
	p->number = content;
	p->order = 0;
	p->processed = 0;
	return (p);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*p;

	if (!lst)
		return (0);
	p = lst;
	while (p->next)
		p = p->next;
	return (p);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (lst)
	{
		if (!(*lst))
			*lst = new;
		else
			ft_lstlast(*lst)->next = new;
	}
}

int	ft_lstsize(t_list *lst)
{
	int	i;

	if (!lst)
		return (0);
	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

void	ft_reset_sort(t_sort *sort)
{
	sort->stack_a = 0;
	sort->stack_b = 0;
	sort->min = 1;
	sort->processed = 0;
	sort->iteration = 0;
	sort->commands = 0;
}
