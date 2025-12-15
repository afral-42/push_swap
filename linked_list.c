#include "stack.h"

t_list	*lstnew(void *data)
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

void	lstdel_front(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!(lst && *lst))
		return ;
	tmp = (*lst)->next;
	del((*lst)->data);
	free(*lst);
	*lst = tmp;
	(*lst)->prev = NULL;
}

void	lst_delone(t_list *node, void ((del)(void *)))
{
	if (!(del && node))
		return ;
	del(node->data);
	free(node);
}

void	*free_lst(t_list *lst, void (*del)(void *))
{
	t_list	*node;
	t_list	*temp;
	
	node = lst;
	while (node)
	{
		temp = node->next;
		lst_delone(node, &free);
		node = temp;
	}
	return (NULL);
}

