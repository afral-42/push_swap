/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounoua <abounoua@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 10:25:15 by abounoua          #+#    #+#             */
/*   Updated: 2025/12/17 12:00:49 by abounoua         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	parse_options(char *args)
{
	args++;
	return (0);
}

t_stack	*parse_stack(char *stack)
{
	t_stack	*a;
	char	**numbers_tab;
	int		error;
	int		nb;

	a = NULL;
	error = 0;
	numbers_tab = ft_split(stack, ' ');
	while (*numbers_tab)
	{
		nb = ft_atoi_secured((const char *)*numbers_tab, &error);
		if (error == -1)
		{
			free_stack(a);
			return ((t_stack *)free_split);
		}
		push(a, nb);
		numbers_tab++;
	}
	return (a);
}

void	parsing(char *stack, char *args, t_stack **a, int *options)
{
	if (!stack || !args)
		return ;
	*a = parse_stack(stack);
	*options = parse_options(args);
}

int main(int ac, char **av)
{
    t_stack		*a;
	t_stack		*b;
	int			options;

	a = NULL;
	b = NULL;
	options = 0;
	if (ac == 1)
		return (1);
	if (ac > 3)
	{
		write(2, "Error\n", 6);
		return (1);
    }	
	parsing(av[1], av[2], &a, &options);
	if (!a || !options)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	print_list(a->top);
}