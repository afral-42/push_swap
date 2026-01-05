/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounoua <abounoua@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 10:33:20 by arebilla          #+#    #+#             */
/*   Updated: 2026/01/05 14:32:03 by abounoua         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHMS_H
# define ALGORITHMS_H

# include "stack.h"

int		abort_sort_function(t_stack *b);
int		insertion_sort(t_stack *a);
int 	selection_sort(t_stack *a);
int		transfer_stack(t_stack *dest, t_stack *src,
			int (*push_fct)(t_stack *, t_stack *));
size_t	ft_sqrt(size_t nb);
int	bucket_sort(t_stack *a);

#endif
