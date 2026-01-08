/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebilla <arebilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 10:33:20 by arebilla          #+#    #+#             */
/*   Updated: 2026/01/08 11:33:54 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHMS_H
# define ALGORITHMS_H

# include "stack.h"
# include "operations.h"

t_ops_counter	*insertion_sort(t_stack *a);
int				transfer_stack(t_stack *dest, t_stack *src,
					t_ops_counter *ops_count,
					int (*push_fct)(t_stack *, t_stack *, t_ops_counter *));
size_t			get_insertion_index(t_stack *stack, int value);
size_t			get_insertion_index_from_bottom(t_stack *stack, int value);
size_t			get_insertion_index_from_top(t_stack *stack, int value);

#endif
