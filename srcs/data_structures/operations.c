/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounoua <abounoua@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:29:44 by abounoua          #+#    #+#             */
/*   Updated: 2025/12/27 10:57:33 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	swap(t_stack *stack)
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

void	rotate(t_stack *stack)
{
	t_list	*last;
	t_list	*second;

	if (!stack || !(stack->top) || !(stack->top->next))
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
	stack->position = (stack->position + 1) % stack->size;
}

void	reverse_rotate(t_stack *stack)
{
	t_list	*last;

	if (!stack || !(stack->top) || !(stack->top->next))
		return ;
	last = stack->top;
	while (last->next)
		last = last->next;
	stack->top->prev = last;
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = stack->top;
	stack->top = last;
	stack->position = ((stack->position - 1) % (ssize_t)stack->size + (ssize_t)stack->size) % (ssize_t)stack->size;
}

int	pop(t_stack *stack)
{
	int		data;
	t_list	*top;

	top = stack->top;
	data = top->data;
	if (stack->top->next)
	{
		top->next->prev = NULL;
		stack->top = top->next;
	}
	else
		stack->top = NULL;
	free(top);
	stack->size--;
	return (data);
}
