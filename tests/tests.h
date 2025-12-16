#include "stack.h"
#include "list.h"
#include <assert.h>
#include <stdlib.h>

t_list	*generate_list(size_t size);
void	check_list_integrity(t_list *lst);
t_stack	*generate_stack(size_t size);
