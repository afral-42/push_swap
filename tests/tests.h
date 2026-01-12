#include "stack.h"
#include "list.h"
#include "operations.h"
#include "algorithms.h"
#include <assert.h>
#include <stdlib.h>

t_list	*generate_list(size_t size);
void	check_list_integrity(t_list *lst);
t_stack	*generate_stack(size_t size);
t_stack	*generate_max_disorder_stack(size_t size);
int		stack_is_sorted(t_stack *stack);
void	test_sorting_with_maximum_disorder_stack(void (sort)(t_stack *, t_ops_counter *));
void	test_sorting_with_already_sorted_stack(void (sort)(t_stack *, t_ops_counter *));
void	test_sorting_with_average_disorder_stack(void (sort)(t_stack *, t_ops_counter *));
t_stack	*generate_custom_stack(int	*numbers, size_t size);
