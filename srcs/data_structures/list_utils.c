/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebilla <arebilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 19:12:26 by arebilla          #+#    #+#             */
/*   Updated: 2026/01/08 19:13:13 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "list.h"

int	lstget(t_list *lst, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		lst = lst->next;
		i++;
	}
	return (lst->data);
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

t_list	*lstlast(t_list *lst)
{
	while (lst->next)
		lst = lst->next;
	return (lst);
}

size_t	get_min_index(t_list *lst)
{
	int		min;
	size_t	i;
	size_t	min_index;

	min = lst->data;
	min_index = 0;
	i = 1;
	lst = lst->next;
	while (lst)
	{
		if (lst->data < min)
		{
			min = lst->data;
			min_index = i;
		}
		lst = lst->next;
		i++;
	}
	return (min_index);
}
