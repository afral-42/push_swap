#include "stack.h"

void	swap(t_stack *stack)
{
	if (stack->size == 0)
		return ;
	lst_swap_head_nodes(&(stack->top));
}

void	double_swap(t_stack *a, t_stack *b)
{
	lst_swap_head_nodes(&(a->top));
	lst_swap_head_nodes(&(b->top));
}

void	rotate(t_stack *stack)
{
	if (stack->size == 0)
		return ;
	lst_rotate(&(stack->top));
}

void	reverse_rotate(t_stack *stack)
{
	if (stack->size == 0)
		return ;
	lst_reverse_rotate(&(stack->top));
}

void	push(t_stack *a, t_stack *b)
{
	if (b->size == 0)
		return ;
	push_st(a, pop_st(b));
}

