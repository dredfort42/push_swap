#include "push_swap.h"

/**
 * @brief Handles errors by freeing the stack and printing an error message.
 *
 * @param stack The stack to be freed.
 * @return short Returns SUCCESS.
 */
static short ft_error(t_list *stack)
{
	ft_free_stack(stack);
	write(0, "Error\n", 6);
	return (SUCCESS);
}

/**
 * @brief Parses a string of numbers separated by spaces and adds them to the stack.
 *
 * @param str The input string containing numbers.
 * @param stack The stack to which the numbers will be added.
 * @return int Returns TRUE if parsing is successful, FALSE otherwise.
 */
int ft_parsing_string(char *str, t_list **stack)
{
	int i;
	long int tmp;

	i = 0;
	while (str[i])
	{
		tmp = ft_atoi(&str[i]);
		if (tmp > INT_MAX || tmp < INT_MIN || !ft_digits_in_str(&str[i]) || ft_is_num_in_stack(tmp, *stack))
			return (FALSE);
		ft_lstadd_back(stack, ft_lstnew(tmp));
		while (str[i] && str[i] != ' ')
			i++;
		while (str[i] && str[i] == ' ')
			i++;
	}
	return (TRUE);
}

// The main function to run the push_swap program
int main(int argc, char **argv)
{
	t_list *stack;
	int i;

	stack = NULL;
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
	return (SUCCESS);
}
