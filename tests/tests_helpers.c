#include "tests.h"

void	check_list_integrity(t_list *lst)
{
	t_list	*node;

	node = lst;
	if (!node)
		return ;
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

t_stack	*generate_max_disorder_stack(size_t size)
{
	t_stack	*stack;
	size_t	i;

	stack = init_stack();
	i = 1;
	while (i <= size)
		push(stack, i++);
	return (stack);
}

t_stack	*generate_custom_stack(int	*numbers, size_t size)
{
	size_t	i;
	t_stack	*stack;

	i = 0;
	stack = init_stack();
	while (i < size)
	{
		push(stack, numbers[size - 1 - i]);
		i++;
	}
	return (stack);
}

int	stack_is_sorted(t_stack *stack)
{
	return (compute_disorder(stack) == 0);
}

void	test_sorting_with_already_sorted_stack(t_ops_counter *(*sort)(t_stack *))
{
	t_stack	*stack;

	stack = generate_stack(0);
	assert(lstcheck_duplicate(stack->top) == 0);
	assert(stack_is_sorted(stack));
	sort(stack);
	assert(lstcheck_duplicate(stack->top) == 0);
	assert(stack_is_sorted(stack));
	free_stack(stack);
	stack = generate_stack(1);
	assert(stack_is_sorted(stack));
	sort(stack);
	assert(lstcheck_duplicate(stack->top) == 0);
	assert(stack_is_sorted(stack));
	free_stack(stack);
	stack = generate_stack(2);
	assert(stack_is_sorted(stack));
	sort(stack);
	assert(lstcheck_duplicate(stack->top) == 0);
	assert(stack_is_sorted(stack));
	free_stack(stack);
	stack = generate_stack(10);
	assert(stack_is_sorted(stack));
	sort(stack);
	assert(lstcheck_duplicate(stack->top) == 0);
	assert(stack_is_sorted(stack));
	free_stack(stack);
}

void	test_sorting_with_maximum_disorder_stack(t_ops_counter *(*sort)(t_stack *))
{
	t_stack	*stack;

	stack = generate_max_disorder_stack(2);
	assert(compute_disorder(stack) == 1.0);
	sort(stack);
	assert(lstcheck_duplicate(stack->top) == 0);
	assert(stack_is_sorted(stack));
	free_stack(stack);
	stack = generate_max_disorder_stack(3);
	assert(compute_disorder(stack) == 1.0);
	sort(stack);
	assert(lstcheck_duplicate(stack->top) == 0);
	assert(stack_is_sorted(stack));
	free_stack(stack);
	stack = generate_max_disorder_stack(10);
	assert(compute_disorder(stack) == 1.0);
	sort(stack);
	assert(lstcheck_duplicate(stack->top) == 0);
	assert(stack_is_sorted(stack));
	free_stack(stack);
}

void	test_sorting_with_average_disorder_stack(t_ops_counter *(*sort)(t_stack *))
{
	int		numbers[10] = {2, 11, 10, 16, 7, 6, 12, 3, 5, 1};
	t_stack	*stack;

	stack = generate_custom_stack(numbers, 10);
	assert(compute_disorder(stack) < 1.0 && compute_disorder(stack) > 0);
	sort(stack);
	assert(lstcheck_duplicate(stack->top) == 0);
	assert(stack_is_sorted(stack));
	free_stack(stack);
}
