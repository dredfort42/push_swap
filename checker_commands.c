#include "push_swap.h"

static short	ft_strlen(char *str)
{
	short	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_execute_command_sx(t_sort *sort, char *command)
{
	if (command[1] == 'a')
		ft_sa(sort);
	else if (command[1] == 'b')
		ft_sb(sort);
	else
		ft_ss(sort);
}

void	ft_execute_command_rx(t_sort *sort, char *command)
{
	if (command[1] == 'a')
		ft_ra(sort);
	else if (command[1] == 'b')
		ft_rb(sort);
	else
		ft_rr(sort);
}

void 	ft_detect_command(t_sort *sort, char *command)
{
	short	strlen;

	strlen = ft_strlen(command);
	if (strlen == 3 && command[0] == 's'
		&& (command[1] == 's' || command[1] == 'a' || command[1] == 'b'))
		ft_execute_command_sx(sort, command);
	else if (strlen == 3 && command[0] == 'p' && command[1] == 'a')
		ft_pa(sort);
	else if (strlen == 3 && command[0] == 'p' && command[1] == 'b')
		ft_pb(sort);
	else if (strlen == 4 && command[0] == 'r'
		&& command[1] == 'r' && command[2] == 'r')
		ft_rrr(sort);
	else if (strlen == 4 && command[0] == 'r' && command[1] == 'r'
		&& command[2] == 'a')
		ft_rra(sort);
	else if (strlen == 4 && command[0] == 'r' && command[1] == 'r'
		&& command[2] == 'b')
		ft_rrb(sort);
	else if (strlen == 3 && command[0] == 'r' && (command[1] == 'r'
			|| command[1] == 'a' || command[1] == 'b'))
		ft_execute_command_rx(sort, command);
	else
		ft_error_ck(sort);
}

short	ft_get_command(t_sort *sort)
{
	char	command[5];
	int		bytes_was_read;
	int		i;

	i = 0;
	bytes_was_read = 1;
	while (bytes_was_read)
	{
		bytes_was_read = read(0, &command[i], 1);
		if (bytes_was_read < 0)
			return (-1);
		i++;
		if (command[i - 1] == '\n')
		{
			ft_detect_command(sort, command);
			i = 0;
			while (command[i])
			{
				command[i++] = 0;
			}
			i = 0;
		}
	}
	return (0);
}
