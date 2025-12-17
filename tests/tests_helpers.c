#include "tests.h"

void	check_list_integrity(t_list *lst)
{
	t_list	*node;

	node = lst;
	while (node->next)
	{
		assert(node->next->prev == node);
		node = node->next;
	}
}

t_list	*generate_list(size_t size)
{
	int		data;
	t_list	*lst;

	if (!size)
		return NULL;
	data = size;
	lst = lstnew(data);
	size--;
	while (size)
		lstadd_front(&lst, lstnew(size--));
	return (lst);
}

t_stack	*generate_stack(size_t size)
{
	t_stack	*stack;

	stack = init_stack();
	while (size)
		push(stack, size--);
	return (stack);
}

int	stack_is_sorted(t_stack *stack)
{
	t_list	*node;

	node = stack->top;
	while (node && node->next)
	{
		if (node->data > node->next->data)
			return (0);
		node = node->next;
	}
	return (1);
}
