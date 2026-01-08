/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebilla <arebilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 09:23:01 by arebilla          #+#    #+#             */
/*   Updated: 2026/01/07 13:49:02 by arebilla         ###   ########.fr       */
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

int				push_a(t_stack *a, t_stack *b, t_ops_counter *counter);
int				push_b(t_stack *b, t_stack *a, t_ops_counter *counter);
int				rotate_a(t_stack *a, t_ops_counter *counter);
int				rotate_b(t_stack *b, t_ops_counter *counter);
int				rotate_both(t_stack *a, t_stack *b, t_ops_counter *counter);
int				reverse_rotate_a(t_stack *a, t_ops_counter *counter);
int				reverse_rotate_b(t_stack *b, t_ops_counter *counter);
int				reverse_rotate_both(t_stack *a, t_stack *b,
					t_ops_counter *counter);
int				swap_a(t_stack *a, t_ops_counter *counter);
int				swap_b(t_stack *b, t_ops_counter *counter);
int				swap_both(t_stack *a, t_stack *b, t_ops_counter *counter);
t_ops_counter	*new_ops_counter(void);
int				get_total_operations(t_ops_counter *ops_count);

#endif
