/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_counter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounoua <abounoua@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 12:13:00 by arebilla          #+#    #+#             */
/*   Updated: 2026/01/15 18:34:25 by abounoua         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

t_ops_counter	*new_ops_counter(void)
{
	t_ops_counter	*ops_counter;

	ops_counter = malloc(sizeof(t_ops_counter));
	if (!ops_counter)
		return (NULL);
	ops_counter->pa = 0;
	ops_counter->pb = 0;
	ops_counter->ra = 0;
	ops_counter->rb = 0;
	ops_counter->rr = 0;
	ops_counter->rra = 0;
	ops_counter->rrb = 0;
	ops_counter->rrr = 0;
	ops_counter->sa = 0;
	ops_counter->sb = 0;
	ops_counter->ss = 0;
	ops_counter->print_flag = 1;
	return (ops_counter);
}

int	get_total_operations(t_ops_counter *ops_count)
{
	return (ops_count->pa + ops_count->pb + ops_count->ra + ops_count->rb
		+ ops_count->rr + ops_count->rra + ops_count->rrb + ops_count->rrr
		+ ops_count->sa + ops_count->sb + ops_count->ss);
}
