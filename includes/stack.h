/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounoua <abounoua@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 16:12:08 by abounoua          #+#    #+#             */
/*   Updated: 2025/12/17 17:43:51 by abounoua         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "list.h"
# include <sys/types.h>

typedef struct s_stack
{
	t_list	*top;
	size_t	size;
}	t_stack;

t_stack	*init_stack(void);
void	*free_stack(t_stack *stack);
int		push(t_stack *stack, int data);
int		pop(t_stack *stack);
double	compute_disorder(t_stack *stack);
void	swap(t_stack *stack);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);

#endif
