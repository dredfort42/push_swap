#include "push_swap.h"

static void ft_command(t_list *p)
{
	if (p->number == SA)
		write(1, "sa\n", 3);
	else if (p->number == SB)
		write(1, "sb\n", 3);
	else if (p->number == SS)
		write(1, "ss\n", 3);
	else if (p->number == PA)
		write(1, "pa\n", 3);
	else if (p->number == PB)
		write(1, "pb\n", 3);
	else if (p->number == RA)
		write(1, "ra\n", 3);
	else if (p->number == RB)
		write(1, "rb\n", 3);
	else if (p->number == RR)
		write(1, "rr\n", 3);
	else if (p->number == RRA)
		write(1, "rra\n", 4);
	else if (p->number == RRB)
		write(1, "rrb\n", 4);
	else if (p->number == RRR)
		write(1, "rrr\n", 4);
}

void ft_print_commands(t_sort *sort)
{
	t_list *p;

	p = sort->commands;
	while (p)
	{
		ft_command(p);
		p = p->next;
	}
	ft_free_stack(sort->commands);
}
