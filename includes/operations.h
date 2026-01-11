/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounoua <abounoua@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 09:23:01 by arebilla          #+#    #+#             */
/*   Updated: 2026/01/07 15:15:26 by abounoua         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "stack.h"

typedef struct s_ops_counter
{
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	sa;
	int	sb;
	int	ss;
}	t_ops_counter;

void			push_a(t_stack *a, t_stack *b, t_ops_counter *counter);
void			push_b(t_stack *b, t_stack *a, t_ops_counter *counter);
void			rotate_a(t_stack *a, t_ops_counter *counter);
void			rotate_b(t_stack *b, t_ops_counter *counter);
void			rotate_both(t_stack *a, t_stack *b, t_ops_counter *counter);
void			reverse_rotate_a(t_stack *a, t_ops_counter *counter);
void			reverse_rotate_b(t_stack *b, t_ops_counter *counter);
void			reverse_rotate_both(t_stack *a, t_stack *b,
					t_ops_counter *counter);
void			swap_a(t_stack *a, t_ops_counter *counter);
void			swap_b(t_stack *b, t_ops_counter *counter);
void			swap_both(t_stack *a, t_stack *b, t_ops_counter *counter);
t_ops_counter	*new_ops_counter(void);
int				get_total_operations(t_ops_counter *ops_count);

#endif
