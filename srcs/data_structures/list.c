/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounoua <abounoua@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:28:26 by abounoua          #+#    #+#             */
/*   Updated: 2026/01/05 13:01:39 by abounoua         ###   ########lyon.fr   */
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

int	lstget_max(t_list *lst)
{
	int	max;

	max = lst->data;
	lst = lst->next;
	while (lst)
	{
		if (lst->data > max)
			max = lst->data;
		lst = lst->next;
	}
	return (max);
}

int	lstget_min(t_list *lst)
{
	int	min;

	min = lst->data;
	lst = lst->next;
	while (lst)
	{
		if (lst->data < min)
			min = lst->data;
		lst = lst->next;
	}
	return (min);
}