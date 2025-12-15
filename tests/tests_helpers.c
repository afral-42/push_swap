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
