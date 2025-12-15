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

void	lst_swap_head_nodes(t_list **lst)
{
	t_list	*cpy_head;
	t_list	*cpy_second_node;
	t_list	*cpy_third_node;

	cpy_head = *lst;
	if (!lst)
		return;
	cpy_second_node = cpy_head->next;
	if (!cpy_second_node)
		return;
	cpy_third_node = cpy_second_node->next;
	cpy_head->prev = cpy_second_node;
	cpy_head->next = cpy_third_node;
	cpy_second_node->prev = NULL;
	cpy_second_node->next = cpy_head;
	if (cpy_third_node)
		cpy_third_node->prev = cpy_head;
	*lst = cpy_second_node;
}

void	lst_rotate(t_list **lst)
{
	t_list	*cpy_head;
	t_list	*cpy_second_elt;
	t_list	*cpy_tail;

	cpy_head = *lst;
	if (!lst)
		return ;
	if (!(cpy_head->next))
		return ;
	cpy_second_elt = cpy_head->next;
	cpy_tail = cpy_second_elt;
	while (cpy_tail->next)
		cpy_tail = cpy_tail->next;
	cpy_head->prev = cpy_tail;
	cpy_head->next = NULL;
	cpy_second_elt->prev = NULL;
	cpy_tail->next = cpy_head;
	*lst = cpy_second_elt;
}

void	lst_reverse_rotate(t_list **lst)
{
	t_list	*cpy_head;
	t_list	*cpy_penultimate_elt;
	t_list	*cpy_tail;

	cpy_head = *lst;
	if (!lst)
		return ;
	if (!(cpy_head->next))
		return ;
	cpy_tail = cpy_head->next;
	while (cpy_tail->next)
		cpy_tail = cpy_tail->next;
	cpy_penultimate_elt = cpy_tail->prev;
	cpy_head->prev = cpy_tail;
	cpy_penultimate_elt->next = NULL;
	cpy_tail->next = cpy_head;
	cpy_tail->prev = NULL;
	*lst = cpy_tail;
}
