/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounoua <abounoua@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 15:15:08 by abounoua          #+#    #+#             */
/*   Updated: 2026/01/05 12:58:47 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "parsing.h"
#include "algorithms.h"
#include "ft_printf.h"
#include "operations.h"

int main(int ac, char **av)
{
    t_stack			*a;
	int				options;
	int				value;
	t_ops_counter	*ops_count;

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
	ops_count = insertion_sort(a);
	if (!ops_count)
		return (1);
	ft_printf("\n\nCompte d'opérations : %d\n\n", get_total_operations(ops_count));
	print_list(a->top);
	free_stack(a);
	free(ops_count);
	return (0);
}
