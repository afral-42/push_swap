/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounoua <abounoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 16:51:01 by abounoua          #+#    #+#             */
/*   Updated: 2025/12/15 16:26:18 by abounoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdio.h>

t_list	*lstnew(int data)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->next = NULL;
	node->prev = NULL;
	node->data = data;
	return (node);
}

void	lstadd_front(t_list **lst, t_list *node)
{
	if (lst && *lst)
	{
		node->next = *lst;
		(*lst)->prev = node;
	}
	*lst = node;
}

void	*free_lst(t_list *lst)
{
	t_list	*node;
	t_list	*temp;
	
	node = lst;
	while (node)
	{
		temp = node->next;
		free(node);
		node = temp;
	}
	return (NULL);
}

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

void	push(t_stack **stack, int data)
{
	t_list	*node;

	node = lstnew(data);
	if (!node || !stack)
		return ;
	if (!(*stack))
	{
		*stack = init_stack();
		if (!(*stack))
			return (free(node));
		(*stack)->top = node;
		(*stack)->size = 1;
	}
	else
	{
		lstadd_front(&((*stack)->top), node);
		(*stack)->size++;
	}
}

void	print_list(t_list *lst)
{
	while (lst)
	{
		printf("%d\n", lst->data);
		lst = lst->next;
	}
}

int	main(void)
{
	t_list	*lst;
	t_list	*node;
	t_stack	*stack;

	lst = NULL;
	
	printf("=============    Tests chained lists    =============\n");
	node = lstnew(0);
	if (!node)
		return (free_lst(lst), 1);
	lstadd_front(&lst, node);

	
	node = lstnew(1);
	if (!node)
		return (free_lst(lst), 1);
	lstadd_front(&lst, node);

	
	node = lstnew(2);
	if (!node)
		return (free_lst(lst), 1);
	lstadd_front(&lst, node);


	node = lstnew(3);
	if (!node)
		return (free_lst(lst), 1);
	lstadd_front(&lst, node);
	print_list(lst);
	free_lst(lst);
	printf("=====================================================\n\n");
	
	printf("==================    Tests stacks    ==================\n");
	stack = NULL;
	push(&stack, 10);
	push(&stack, 9);
	push(&stack, 8);
	push(&stack, 7);
	push(&stack, 6);
	push(&stack, 5);
	push(&stack, 4);
	push(&stack, 3);
	push(&stack, 2);
	push(&stack, 1);
	push(&stack, 0);
	print_list(stack->top);
	printf("\nSize : %zu", stack->size);
	free_stack(stack);
	printf("\n=====================================================\n\n");
}