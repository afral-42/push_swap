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

int				abort_sort_function(t_stack *b);
int				transfer_a_to_b_sorted(t_stack *a, t_stack *b, size_t size,
					int *ops_count);
int				transfer_b_to_a_sorted(t_stack *b, t_stack *a, size_t size,
					int *ops_count);
void			merge_a_in_b(t_stack *b, t_stack *a, size_t size,
					int *ops_count);
void			swap_nodes(t_stack *a, t_stack *b, size_t n, size_t m,
					int *ops_count);
size_t			get_insertion_index(t_stack *stack, int value);
t_ops_counter	*merge_sort(t_stack *a);
t_ops_counter	*insertion_sort(t_stack *a);
t_ops_counter	*quick_sort(t_stack *a);
t_ops_counter	*radix_sort(t_stack *a);
t_ops_counter	*bucket_sort(t_stack *a);
t_ops_counter	*chunk_based_sort(t_stack *a);
size_t			ft_sqrt(size_t n);
int				transfer_stack(t_stack *dest, t_stack *src,
					t_ops_counter *ops_count,
					int (*push_fct)(t_stack *, t_stack *, t_ops_counter *));
size_t			get_insertion_index(t_stack *stack, int value);
size_t			get_insertion_index_from_bottom(t_stack *stack, int value);
size_t			get_insertion_index_from_top(t_stack *stack, int value);

#endif
