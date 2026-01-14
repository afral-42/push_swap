/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounoua <abounoua@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 10:33:20 by arebilla          #+#    #+#             */
/*   Updated: 2026/01/13 16:31:26 by abounoua         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHMS_H
# define ALGORITHMS_H

# include "stack.h"
# include "operations.h"

typedef struct s_buckets
{
	size_t	number;
	size_t	size;
}	t_buckets;

typedef struct s_linearised_tab
{
	int		*tab;
	size_t	size;
}	t_linearised_tab;

typedef struct s_partition
{
	size_t	partition_size;
	size_t	lower_partition_size;
	size_t	upper_partition_size;
	int		mediane;
}	t_partition;

size_t	ft_sqrt(size_t nb);
void	bucket_sort(t_stack *a, t_ops_counter *ops);
void	insertion_sort(t_stack *a, t_ops_counter *ops);
void	quick_sort(t_stack *a, t_ops_counter *ops);
void	merge_sort(t_stack *a, t_ops_counter *ops);
void	selection_sort(t_stack *a, t_ops_counter *ops);
void	radix_sort(t_stack *a, t_ops_counter *ops);
int		transfer_stack(t_stack *dest, t_stack *src,
			t_ops_counter *ops_count,
			void (*push_fct)(t_stack *, t_stack *, t_ops_counter *));
size_t	get_insertion_index(t_stack *stack, int value);
size_t	get_insertion_index_from_bottom(t_stack *stack, int value);
size_t	get_insertion_index_from_top(t_stack *stack, int value);
int		compress_stack(t_stack *a);

int		get_mediane(t_stack *a, int *mediane, size_t partition);
void	process_base_case_a(t_stack *a, t_stack *b, size_t partition,
			t_ops_counter *ops);
void	process_base_case_b(t_stack *b, t_stack *a, size_t partition,
			t_ops_counter *ops);

#endif
