/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebilla <arebilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 10:33:20 by arebilla          #+#    #+#             */
/*   Updated: 2026/01/05 12:46:38 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHMS_H
# define ALGORITHMS_H

# include "stack.h"
# include "operations.h"

int		abort_sort_function(t_stack *b);
int		transfer_a_to_b_sorted(t_stack *a, t_stack *b, size_t size, int *ops_count);
int		transfer_b_to_a_sorted(t_stack *b, t_stack *a, size_t size, int *ops_count);
void	merge_a_in_b(t_stack *b, t_stack *a, size_t size, int *ops_count);
int		merge_sort(t_stack *a);
void	swap_nodes(t_stack *a, t_stack *b, size_t n, size_t m, int *ops_count);
int		quick_sort(t_stack *a);
int		radix_sort(t_stack *a);
int		bucket_sort(t_stack *a);
size_t	ft_sqrt(size_t n);
t_ops_counter	*insertion_sort(t_stack *a);
int				transfer_stack(t_stack *dest, t_stack *src, t_ops_counter *ops_count,
					int (*push_fct)(t_stack *, t_stack *, t_ops_counter *));

#endif
