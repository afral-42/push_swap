/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounoua <abounoua@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 09:23:01 by arebilla          #+#    #+#             */
/*   Updated: 2025/12/19 11:27:36 by abounoua         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "stack.h"

int	push_a(t_stack *a, t_stack *b);
int	push_b(t_stack *b, t_stack *a);
int	rotate_a(t_stack *a);
int	rotate_b(t_stack *b);
int	rotate_both(t_stack *a, t_stack *b);
int	reverse_rotate_a(t_stack *a);
int	reverse_rotate_b(t_stack *b);
int	reverse_rotate_both(t_stack *a, t_stack *b);
int	swap_a(t_stack *a);
int	swap_b(t_stack *b);
int	swap_both(t_stack *a, t_stack *b);

#endif
