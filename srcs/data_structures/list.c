/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounoua <abounoua@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:28:26 by abounoua          #+#    #+#             */
/*   Updated: 2026/01/09 13:13:46 by abounoua         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

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

int	lstcheck_duplicate(t_list *lst)
{
	t_list	*i;
	t_list	*j;

	if (!lst)
		return (0);
	i = lst;
	while (i->next)
	{
		j = i->next;
		while (j)
		{
			if (i->data == j->data)
				return (1);
			j = j->next;
		}
		i = i->next;
	}
	return (0);
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

void	lst_move_head(t_list **dest, t_list **src)
{
	t_list	*tmp_node;

	tmp_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	tmp_node->next = *dest;
	tmp_node->prev = NULL;
	if (*dest)
		(*dest)->prev = tmp_node;
	*dest = tmp_node;
}
