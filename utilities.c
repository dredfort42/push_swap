#include "push_swap.h"

/**
 * @brief Converts a string to a long integer.
 *
 * @param str The input string.
 * @return long int The converted long integer.
 */
long int ft_atoi(char *str)
{
	short i;
	short sign;
	long long int num;

	i = 0;
	sign = 1;
	if (str[i] == '+')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	num = 0;
	while (str[i] >= '0' && str[i] <= '9')
		num = num * 10 + (str[i++] - '0');
	if (sign > 0)
		return (num);
	else
		return (-num);
}

/**
 * @brief Counts the number of digit characters in a string.
 *
 * @param str The input string.
 * @return short The count of digit characters.
 */
short ft_digits_in_str(char *str)
{
	short i;
	short j;

	i = 0;
	j = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		i++;
		j++;
	}
	return (j);
}

/**
 * @brief Checks if a number is already included in the stack.
 *
 * @param num The number to check.
 * @param stack The stack to search in.
 * @return int Returns TRUE if the number is found, FALSE otherwise.
 */
int ft_is_num_in_stack(int num, t_list *stack)
{
	t_list *p;

	p = stack;
	while (p)
	{
		if (p->number == num)
			return (TRUE);
		p = p->next;
	}
	return (FALSE);
}

/**
 * @brief Assigns an order to the smallest unprocessed element in the stack.
 *
 * @param sort Pointer to the sorting structure containing the stack.
 * @param i The order to assign.
 */
static void ft_order(t_sort *sort, int i)
{
	int min;
	t_list *p;

	p = sort->stack_a;
	while (p->order)
		p = p->next;
	min = p->number;
	while (p)
	{
		if (!p->order && p->number < min)
			min = p->number;
		p = p->next;
	}
	p = sort->stack_a;
	while (p)
	{
		if (p->number == min)
			p->order = i;
		p = p->next;
	}
}

/**
 * @brief Determines the order of elements in the stack.
 *
 * @param sort Pointer to the sorting structure containing the stack.
 */
void ft_determine_order(t_sort *sort)
{
	int i;
	int lst_size;

	i = 0;
	lst_size = ft_lstsize(sort->stack_a);
	while (i <= lst_size)
	{
		ft_order(sort, i);
		i++;
	}
}
