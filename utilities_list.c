#include "push_swap.h"

/**
 * @brief Creates a new list element with the given content.
 *
 * @param content The integer content for the new element.
 * @return t_list* The newly created list element.
 */
t_list *ft_lstnew(int content)
{
	t_list *p;

	p = (t_list *)malloc(sizeof(t_list));
	if (!p)
		return (0);
	p->next = 0;
	p->number = content;
	p->order = 0;
	p->processed = 0;
	return (p);
}

/**
 * @brief Returns the last element of the list.
 *
 * @param lst The beginning of the list.
 * @return t_list* The last element of the list.
 */
t_list *ft_lstlast(t_list *lst)
{
	t_list *p;

	if (!lst)
		return (0);
	p = lst;
	while (p->next)
		p = p->next;
	return (p);
}

/**
 * @brief Adds a new element at the end of the list.
 *
 * @param lst The address of the pointer to the first link of the list.
 * @param new The new element to be added to the list.
 */
void ft_lstadd_back(t_list **lst, t_list *new)
{
	if (lst)
	{
		if (!(*lst))
			*lst = new;
		else
			ft_lstlast(*lst)->next = new;
	}
}

/**
 * @brief Counts the number of elements in the list.
 *
 * @param lst The beginning of the list.
 * @return int The number of elements in the list.
 */
int ft_lstsize(t_list *lst)
{
	int i;

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

/**
 * @brief Resets the sorting structure to its initial state.
 *
 * @param sort The sorting structure to reset.
 */
void ft_reset_sort(t_sort *sort)
{
	sort->stack_a = 0;
	sort->stack_b = 0;
	sort->min = 1;
	sort->processed = 0;
	sort->iteration = 0;
	sort->commands = 0;
}
