/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebilla <arebilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 08:50:18 by arebilla          #+#    #+#             */
/*   Updated: 2026/01/12 09:11:46 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "stack.h"

int	read_ops(t_stack *a)
{
	(void)a;
	return (0);
}

int	process_result(int read_ops_result)
{
	if (read_ops_result == -1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (read_ops_result == 1)
	{
		write(2, "KO\n", 3);
		return (1);
	}
	else
	{
		write(1, "OK\n", 3);
		return (0);
	}
}

int	main(int ac, char **av)
{
	t_stack	*a;
	int		options;
	int		value;
	int		read_ops_result;

	options = 0;
	if (ac == 1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	value = parser(ac, av, &a, &options);
	if (value == -1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	read_ops_result = read_ops(a);
	free_stack(a);
	return (process_result(read_ops_result));
}
