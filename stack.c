/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounoua <abounoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 16:51:01 by abounoua          #+#    #+#             */
/*   Updated: 2025/12/15 18:53:48 by arebilla         ###   ########.fr       */
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
	free_lst(stack->top, &free);
	free(stack);
	return (NULL);
}

void	push(t_stack **stack, int data)
{
	t_list	*node;
	int		*p_data;

	if (!stack)
		return ;
	p_data = malloc(sizeof(int));
	if (!p_data)
		return ;
	*p_data = data;
	node = lstnew(p_data);
	if (!node)
		return (free(p_data));
	if (!(*stack))
	{
		*stack = init_stack();
		if (!(*stack))
			return (lst_delone(node, &free));
		(*stack)->top = node;
		(*stack)->size = 1;
	}
	else
	{
		lstadd_front(&((*stack)->top), node);
		(*stack)->size++;
	}
}

int	stack_is_empty(t_stack *stack)
{
	return (stack->size == 0);
}

int	pop(t_stack *stack)
{
	int	data;

	data = *(int *)(stack->top->data);
	lstdel_front(&(stack->top), &free);
	stack->size--;
	return (data);
}

void	swap(t_stack *stack)
{
	lst_swap_head_nodes(&(stack->top));
}

void	rotate(t_stack *stack)
{
	lst_rotate(&(stack->top));
}

void	reverse_rotate(t_stack *stack)
{
	lst_reverse_rotate(&(stack->top));
}

void	push_op(t_stack **a, t_stack *b)
{
	int	data;

	if (b->size == 0)
		return ;
	data = pop(b);
	push(a, data);
}

void	print_list(t_list *lst)
{
	while (lst)
	{
		printf("%d\n", *(int *)(lst->data));
		lst = lst->next;
	}
}


int	main(void)
{
	t_list	*lst;
	t_list	*node;
	t_stack	*stack;
	t_stack	*stackb;
	int		*a = malloc(sizeof(int));
	int		*b = malloc(sizeof(int));
	int		*c = malloc(sizeof(int));
	int		*d = malloc(sizeof(int));

	*a = 0;
	*b = 1;
	*c = 2;
	*d = 3;
	lst = NULL;
	
	printf("=============    Tests chained lists    =============\n");
	node = lstnew(a);
	if (!node)
		return (free_lst(lst, &free), 1);
	lstadd_front(&lst, node);

	
	node = lstnew(b);
	if (!node)
		return (free_lst(lst, &free), 1);
	lstadd_front(&lst, node);

	
	node = lstnew(c);
	if (!node)
		return (free_lst(lst, &free), 1);
	lstadd_front(&lst, node);


	node = lstnew(d);
	if (!node)
		return (free_lst(lst, &free), 1);
	lstadd_front(&lst, node);
	print_list(lst);
	free_lst(lst, &free);
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
	printf("\nSize : %zu\n", stack->size);
	printf("\nswap: \n");
	swap(stack);
	print_list(stack->top);
	printf("\nrotate: \n");
	rotate(stack);
	print_list(stack->top);
	printf("\nrotate: \n");
	rotate(stack);
	print_list(stack->top);
	printf("\nreverse rotate: \n");
	reverse_rotate(stack);
	print_list(stack->top);
	printf("\nreverse rotate: \n");
	reverse_rotate(stack);
	print_list(stack->top);
	printf("pop: %i\n", pop(stack));
	printf("pop: %i\n", pop(stack));
	printf("pop: %i\n", pop(stack));
	printf("pop: %i\n", pop(stack));
	printf("pop: %i\n", pop(stack));
	printf("pop: %i\n", pop(stack));
	printf("pop: %i\n", pop(stack));
	printf("pop: %i\n", pop(stack));
	printf("pop: %i\n", pop(stack));
	print_list(stack->top);
	printf("\nSize : %zu", stack->size);
	stackb = NULL;
	push_op(&stackb, stack);
	printf("push_op\nstack:\n");
	print_list(stack->top);
	printf("stackb:\n");
	print_list(stackb->top);
	free_stack(stack);
	free_stack(stackb);
	printf("\n=====================================================\n\n");
}
