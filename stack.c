/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounoua <abounoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 16:51:01 by abounoua          #+#    #+#             */
/*   Updated: 2025/12/16 14:30:47 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdio.h>

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->size = 0;
	stack->top = NULL;
	return (stack);
}

void	*free_stack(t_stack *stack)
{
	free_lst(stack->top);
	free(stack);
	return (NULL);
}

void	push_st(t_stack *stack, int data)
{
	t_list	*node;

	if (!stack)
		return ;
	node = lstnew(data);
	if (!node)
		return ;
	lstadd_front(&(stack->top), node);
	stack->size++;
}

int	stack_is_empty(t_stack *stack)
{
	return (stack->size == 0);
}

int	pop_st(t_stack *stack)
{
	int	data;

	data = stack->top->data;
	lstdel_front(&(stack->top));
	stack->size--;
	return (data);
}
