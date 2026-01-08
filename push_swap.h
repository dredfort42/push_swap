#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include <stdlib.h>
#include <libc.h>
#include <limits.h>

#define SUCCESS 0
#define ERROR 1

#define TRUE 1
#define FALSE 0

typedef struct s_list
{
	int number;
	short order;
	short processed;
	struct s_list *next;
} t_list;

typedef struct s_sort
{
	short min;
	short max;
	short mid;
	short processed;
	short iteration;
	t_list *stack_a;
	t_list *stack_b;
	t_list *commands;
} t_sort;

t_list *ft_lstnew(int content);
t_list *ft_lstlast(t_list *lst);
t_list *ft_stack_copy(t_list **stack);
void ft_sa(t_sort *sort);
void ft_sb(t_sort *sort);
void ft_ss(t_sort *sort);
void ft_pa(t_sort *sort);
void ft_pb(t_sort *sort);
void ft_ra(t_sort *sort);
void ft_rb(t_sort *sort);
void ft_rr(t_sort *sort);
void ft_rra(t_sort *sort);
void ft_rrb(t_sort *sort);
void ft_rrr(t_sort *sort);
void ft_3_sort(t_sort *sort);
void ft_5_sort(t_sort *sort);
void ft_quick_sort_a(t_sort *sort);
void ft_presort_a(t_sort *sort, short mid_reduce);
void ft_sort_a(t_sort *sort);
void ft_presort_b(t_sort *sort);
void ft_sort_b(t_sort *sort);
void ft_lstadd_back(t_list **lst, t_list *new);
void ft_sort(t_list **stack);
void ft_free_stack(t_list *stack);
void ft_determine_order(t_sort *sort);
void ft_print_commands(t_sort *sort);
void ft_reset_sort(t_sort *sort);
short ft_error_ck(t_sort *sort);
short ft_lst_max_order(t_list *lst);
short ft_lst_min_order(t_list *lst);
short ft_is_stack_sorted(t_list *stack);
short ft_digits_in_str(char *str);
short ft_get_command(t_sort *sort);
int ft_lstsize(t_list *lst);
int ft_is_num_in_stack(int num, t_list *stack);
long int ft_atoi(char *str);

#endif
