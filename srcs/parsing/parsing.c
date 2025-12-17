/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounoua <abounoua@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 10:25:15 by abounoua          #+#    #+#             */
/*   Updated: 2025/12/17 10:43:54 by abounoua         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "stack.h"
#include "ft_printf.h"

void	parsing(char *stack, char *args, t_stack **a, int *options)
{
	if (!stack || !args)
		return (NULL);
		
	*a = parse_stack(stack);
	*options = parse_options(options);
}

int main(int ac, char **av)
{
    t_stack		*a;
	t_stack		*b;
	int			options;

	a = NULL;
	b = NULL;
	options = NULL;
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