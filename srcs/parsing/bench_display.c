/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebilla <arebilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 14:15:32 by arebilla          #+#    #+#             */
/*   Updated: 2026/01/07 14:43:47 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "parsing.h"
#include "stack.h"

static void	print_strategy_info(int options, double disorder)
{
	if (options & FLAG_SIMPLE)
		ft_putstr_fd("simple / ", 2);
	else if (options & FLAG_MEDIUM)
		ft_putstr_fd("medium / ", 2);
	else if (options & FLAG_COMPLEX)
		ft_putstr_fd("complex / ", 2);
	else
		ft_putstr_fd("adaptative / ", 2);
	if (options & FLAG_SIMPLE || (options & FLAG_ADAPTIVE && disorder < 0.2))
		ft_putstr_fd("𝑛²", 2);
	else if (options & FLAG_MEDIUM
		|| (options & FLAG_ADAPTIVE && disorder < 0.5))
		ft_putstr_fd("𝑛 √𝑛", 2);
	else
		ft_putstr_fd("𝑛 log 𝑛", 2);
}

static void	print_operations_info(t_ops_counter *ops_counter)
{
	ft_putstr_fd("[bench] sa: ", 2);
	ft_putnbr_fd(ops_counter->sa, 2);
	ft_putstr_fd(" sb: ", 2);
	ft_putnbr_fd(ops_counter->sb, 2);
	ft_putstr_fd(" ss: ", 2);
	ft_putnbr_fd(ops_counter->ss, 2);
	ft_putstr_fd(" pa: ", 2);
	ft_putnbr_fd(ops_counter->pa, 2);
	ft_putstr_fd(" pb: ", 2);
	ft_putnbr_fd(ops_counter->pb, 2);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("[bench] ra: ", 2);
	ft_putnbr_fd(ops_counter->ra, 2);
	ft_putstr_fd(" rb: ", 2);
	ft_putnbr_fd(ops_counter->rb, 2);
	ft_putstr_fd(" rr: ", 2);
	ft_putnbr_fd(ops_counter->rr, 2);
	ft_putstr_fd(" rra: ", 2);
	ft_putnbr_fd(ops_counter->rra, 2);
	ft_putstr_fd(" rrb: ", 2);
	ft_putnbr_fd(ops_counter->rrb, 2);
	ft_putstr_fd(" rrr: ", 2);
	ft_putnbr_fd(ops_counter->rrr, 2);
}

void	print_bench_info(double disorder, int options,
		t_ops_counter *ops_counter)
{
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putdouble_fd(disorder * 100, 2, 2);
	ft_putchar_fd('%', 2);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("[bench] strategy: ", 2);
	print_strategy_info(options, disorder);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(get_total_operations(ops_counter), 2);
	ft_putchar_fd('\n', 2);
	print_operations_info(ops_counter);
	ft_putchar_fd('\n', 2);
}
