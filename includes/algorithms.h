/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounoua <abounoua@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 10:33:20 by arebilla          #+#    #+#             */
/*   Updated: 2026/01/07 11:24:46 by abounoua         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHMS_H
# define ALGORITHMS_H

# include "stack.h"
# include "operations.h"

int		abort_sort_function(t_stack *b);
int 	selection_sort(t_stack *a);
size_t	ft_sqrt(size_t nb);
int	bucket_sort(t_stack *a);
int				abort_sort_function(t_stack *b);
t_ops_counter	*insertion_sort(t_stack *a);
int				transfer_stack(t_stack *dest, t_stack *src, t_ops_counter *ops_count,
					int (*push_fct)(t_stack *, t_stack *, t_ops_counter *));

#endif
