/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounoua <abounoua@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 15:15:08 by abounoua          #+#    #+#             */
/*   Updated: 2026/01/08 19:48:37 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "parsing.h"
#include "algorithms.h"
#include "ft_printf.h"
#include "operations.h"

static void	print_debug_initial_list(t_stack *a, int options)
{
	print_list(a->top);
	display_active_flags(options);
}

static void	print_debug(t_stack *a, t_ops_counter *ops_count)
{
	ft_printf("\n\nCompte d'opérations : %d\n\n",
		get_total_operations(ops_count));
	print_list(a->top);
	ft_printf("\n");
}

static t_ops_counter	*select_sort(t_stack *a, int options)
{
	if (options & FLAG_SIMPLE)
		return (insertion_sort(a));
	else if (options & FLAG_SIMPLE)
		return (insertion_sort(a));
	else if (options & FLAG_SIMPLE)
		return (insertion_sort(a));
	else
		return (insertion_sort(a));
}

int	run_sort_operations(t_stack *a, int options)
{
	t_ops_counter	*ops_count;
	double			disorder;

	disorder = compute_disorder(a);
	if (options & FLAG_DEBUG)
		print_debug_initial_list(a, options);
	ops_count = select_sort(a, options);
	if (!ops_count)
		return (1);
	if (options & FLAG_BENCH)
		print_bench_info(disorder, options, ops_count);
	if (options & FLAG_DEBUG)
		print_debug(a, ops_count);
	free(ops_count);
	return (0);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	int		options;
	int		value;
	int		return_code;

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
	return_code = run_sort_operations(a, options);
	free_stack(a);
	return (return_code);
}
