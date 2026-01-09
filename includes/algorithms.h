/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounoua <abounoua@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 10:33:20 by arebilla          #+#    #+#             */
/*   Updated: 2026/01/09 15:28:42 by arebilla         ###   ########.fr       */
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
} t_buckets;

typedef struct	s_linearised_tab
{
	int		*tab;
	size_t	size;
}	t_linearised_tab;

int				abort_sort_function(t_stack *b);
int				selection_sort(t_stack *a);
size_t			ft_sqrt(size_t nb);
t_ops_counter	*bucket_sort(t_stack *a);
t_ops_counter	*insertion_sort(t_stack *a);
int				transfer_stack(t_stack *dest, t_stack *src,
					t_ops_counter *ops_count,
					int (*push_fct)(t_stack *, t_stack *, t_ops_counter *));
t_ops_counter	*radix_sort(t_stack *a);
t_ops_counter	*quick_sort(t_stack *a);
size_t			get_insertion_index(t_stack *stack, int value);
size_t			get_insertion_index_from_bottom(t_stack *stack, int value);
size_t			get_insertion_index_from_top(t_stack *stack, int value);
int				compress_stack(t_stack *a);

#endif
