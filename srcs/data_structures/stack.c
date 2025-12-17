/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounoua <abounoua@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 16:51:01 by abounoua          #+#    #+#             */
/*   Updated: 2025/12/17 12:43:52 by abounoua         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

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

void	push(t_stack *stack, int data)
{
	t_list	*node;

	if (!stack)
		return ;
	node = lstnew(data);
	if (!node)
		return ; // Il faut sécuriser cet appel pour savoir qu'il y a eu une erreur et stopper le programme (int push)
	lstadd_front(&(stack->top), node);
	stack->size++;
}

double	compute_disorder(t_stack *stack)
{
	int		mistakes;
	int		total_pairs;
	t_list	*first;
	t_list	*second;
	
	if (!(stack->top) || !(stack->top->next))
		return (0);
	mistakes = 0;
	total_pairs = 0;
	first = stack->top;
	while (first != NULL)
	{
		second = first->next;
		while (second != NULL)
		{
			total_pairs += 1;
			if (first->data > second->data)
				mistakes += 1;
			second = second->next;
		}
		first = first->next;
	}
	return ((double)mistakes / total_pairs);
}
