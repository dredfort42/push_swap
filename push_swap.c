#include "push_swap.h"

static short	ft_error(t_list *stack)
{
	ft_free_stack(stack);
	write(0, "Error\n", 6);
	return (0);
}

short 	ft_parsing_string(char *str, t_list **stack)
{
	int			i;
	long int	tmp;

	i = 0;
	while (str[i])
	{
		tmp = ft_atoi(&str[i]);
		if (tmp > INT_MAX || tmp < INT_MIN
			|| !ft_digits_in_str(&str[i]) || ft_check_num_include(tmp, *stack))
			return (0);
		ft_lstadd_back(stack, ft_lstnew(tmp));
		while (str[i] && str[i] != ' ')
			i++;
		while (str[i] && str[i] == ' ')
			i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_list		*stack;
	int			i;

	stack = 0;
	if (argc > 1)
	{
		i = 1;
		while (i < (argc))
		{
			if (!ft_parsing_string(argv[i], &stack))
				return (ft_error(stack));
			i++;
		}
		if (!ft_is_stack_sorted(stack))
			ft_sort(&stack);
	}
	return (0);
}
