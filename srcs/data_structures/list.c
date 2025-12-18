/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounoua <abounoua@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:28:26 by abounoua          #+#    #+#             */
/*   Updated: 2025/12/17 17:49:47 by abounoua         ###   ########lyon.fr   */
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