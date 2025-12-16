/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounoua <abounoua@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:29:44 by abounoua          #+#    #+#             */
/*   Updated: 2025/12/16 17:32:56 by abounoua         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void swap(t_stack *stack)
{
	t_list	*first;
	t_list	*second;
	
	if (!stack || !(stack->top) || !(stack->top->next))
		return ;
	first = stack->top;
	second = first->next;
	if (second->next)
		second->next->prev = first;
	first->next = second->next;
	first->prev = second;
	second->next = first;
	second->prev = NULL;
	stack->top = second;
}

void	swap_both(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
}

void	rotate(t_stack *stack)
{
	t_list	*last;
	t_list	*second;

	if (!stack || !(stack->top->next))
		return ;
	second = stack->top->next;
	last = second;
	while (last->next)
		last = last->next;
	stack->top->prev = last;
	stack->top->next = NULL;
	last->next = stack->top;
	second->prev = NULL;
	stack->top = second;
}

void	rotate_both(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
}

void	reverse_rotate(t_stack *stack)
{
	t_list	*last;

	if (!stack || !(stack->top->next))
		return ;
	last = stack->top;
	while (last->next)
		last = last->next;
	stack->top->prev = last;
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = stack->top;
	stack->top = last;
}

void	reverse_rotate_both(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}