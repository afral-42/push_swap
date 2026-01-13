/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounoua <abounoua@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 15:15:08 by abounoua          #+#    #+#             */
/*   Updated: 2026/01/13 10:20:51 by abounoua         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "parsing.h"
#include "algorithms.h"
#include "ft_printf.h"
#include "operations.h"

static void	print_input_debug_info(t_stack *a)
{
	print_list(a->top);
}

static void	print_output_debug_info(t_stack *a, t_ops_counter *ops_count)
{
	ft_printf("\n\nCompte d'opérations : %d\n\n",
		get_total_operations(ops_count));
	print_list(a->top);
	ft_printf("\n");
}

static t_ops_counter	*select_sort(t_stack *a, int options, double disorder)
{
	t_ops_counter	*ops;

	ops = new_ops_counter();
	if (!ops)
		return (NULL);
	if (!disorder)
		return (ops);
	if (options & FLAG_SIMPLE || (options & FLAG_ADAPTIVE && disorder < 0.2))
		insertion_sort(a, ops);
	else if (options & FLAG_MEDIUM
		|| (options & FLAG_ADAPTIVE && disorder < 0.5))
		bucket_sort(a, ops);
	else if (options & FLAG_COMPLEX
		|| (options & FLAG_ADAPTIVE && disorder >= 0.5))
		quick_sort(a, ops);
	return (ops);
}

static int	run_sort_operations(t_stack *a, int options)
{
	t_ops_counter	*ops_count;
	double			disorder;

	disorder = compute_disorder(a);
	if (options & FLAG_DEBUG)
		print_input_debug_info(a);
	ops_count = select_sort(a, options, disorder);
	if (!ops_count)
		return (1);
	if (options & FLAG_BENCH)
		print_bench_info(disorder, options, ops_count);
	if (options & FLAG_DEBUG)
		print_output_debug_info(a, ops_count);
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
	if (value == -1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return_code = run_sort_operations(a, options);
	free_stack(a);
	return (return_code);
}
