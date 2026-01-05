/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebilla <arebilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 09:23:01 by arebilla          #+#    #+#             */
/*   Updated: 2025/12/27 10:29:07 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "stack.h"

int		push_a(t_stack *a, t_stack *b, int *counter);
int		push_b(t_stack *b, t_stack *a, int *counter);
int		rotate_a(t_stack *a, int *counter);
int		rotate_b(t_stack *b, int *counter);
int		rotate_both(t_stack *a, t_stack *b, int *counter);
int		reverse_rotate_a(t_stack *a, int *counter);
int		reverse_rotate_b(t_stack *b, int *counter);
int		reverse_rotate_both(t_stack *a, t_stack *b, int *counter);
int		swap_a(t_stack *a, int *counter);
int		swap_b(t_stack *b, int *counter);
int		swap_both(t_stack *a, t_stack *b, int *counter);
void	move_a(t_stack *a, size_t end, int *ops_counter);

#endif
