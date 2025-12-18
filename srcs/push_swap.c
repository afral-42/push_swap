/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounoua <abounoua@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 15:15:08 by abounoua          #+#    #+#             */
/*   Updated: 2025/12/18 17:49:02 by abounoua         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "parsing.h"
#include "algorithms.h"
#include "ft_printf.h"

int main(int ac, char **av)
{
    t_stack		*a;
	int			options;
	int			value;

	a = NULL;
	options = 0;
	if (ac == 1)
		return (1);
	value = parser(ac, av, &a, &options);
	if (value == -1 || value == 1)
	{
		if (value == 1)
			return (0);
		write(2, "Error\n", 6);
		return (1);
    }
	print_list(a->top);
	display_active_flags(options);
	ft_printf("\n\nCompte d'opérations : %d\n\n", insertion_sort(a));
	print_list(a->top);
	free_stack(a);
	return (0);
}