#include "push_swap.h"

static void	ft_command(t_list *p)
{
	if (p->number == 1)
		write(1, "sa\n", 3);
	else if (p->number == 4)
		write(1, "pa\n", 3);
	else if (p->number == 5)
		write(1, "pb\n", 3);
	else if (p->number == 7)
		write(1, "ra\n", 3);
	else if (p->number == 8)
		write(1, "rb\n", 3);
	else if (p->number == 10)
		write(1, "rra\n", 4);
	else if (p->number == 11)
		write(1, "rrb\n", 4);
}

void	ft_print_commands(t_sort *sort)
{
	t_list	*p;

	p = sort->commands;
	while (p)
	{
		ft_command(p);
		p = p->next;
	}
	ft_free_stack(sort->commands);
}
