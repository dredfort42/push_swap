#include "push_swap.h"

short ft_error_ck(t_sort *sort)
{
	ft_free_stack(sort->stack_a);
	ft_free_stack(sort->stack_b);
	ft_free_stack(sort->commands);
	write(0, "Error\n", 6);
	exit(0);
}

static short ft_parsing_string_ck(char *str, t_sort *sort)
{
	int i;
	long int tmp;

	i = 0;
	while (str[i])
	{
		tmp = ft_atoi(&str[i]);
		if (tmp > INT_MAX || tmp < INT_MIN || !ft_digits_in_str(&str[i]) || ft_is_num_in_stack(tmp, sort->stack_a))
			return (0);
		ft_lstadd_back(&sort->stack_a, ft_lstnew(tmp));
		while (str[i] && str[i] != ' ')
			i++;
		while (str[i] && str[i] == ' ')
			i++;
	}
	return (1);
}

int main(int argc, char **argv)
{
	t_sort sort;
	int i;

	ft_reset_sort(&sort);
	sort.stack_a = 0;
	if (argc > 1)
	{
		i = 1;
		while (i < (argc))
		{
			if (!ft_parsing_string_ck(argv[i], &sort))
				return (ft_error_ck(&sort));
			i++;
		}
		if (ft_get_command(&sort) < 0)
			return (ft_error_ck(&sort));
		if (!sort.stack_b && ft_is_stack_sorted(sort.stack_a))
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
		ft_free_stack(sort.stack_a);
		ft_free_stack(sort.stack_b);
		ft_free_stack(sort.commands);
	}
	return (0);
}
