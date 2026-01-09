/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_linarisation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebilla <arebilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 15:24:52 by arebilla          #+#    #+#             */
/*   Updated: 2026/01/09 15:29:26 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithms.h"
#include "stack.h"
#include "operations.h"

static int	linearise_stack(t_stack *a, t_linearised_tab *linearised_tab)
{
	size_t	i;
	t_list	*node;

	linearised_tab->tab = malloc(sizeof(int) * a->size);
	if (!(linearised_tab->tab))
		return (-1);
	node = a->top;
	i = 0;
	while (node)
	{
		(linearised_tab->tab)[i] = node->data;
		i++;
		node = node->next;
	}
	linearised_tab->size = a->size;
	return (0);
}

static void	sort_tab(t_linearised_tab *linearised_tab)
{
	int		swapped;
	int		temp;
	int		*tab;
	size_t	i;

	tab = linearised_tab->tab;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		i = 0;
		while (i < linearised_tab->size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				temp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = temp;
				swapped = 1;
			}
			i++;
		}
	}
}

static int	get_rank(int *sorted_tab, int value, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (sorted_tab[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

int	compress_stack(t_stack *a)
{
	t_linearised_tab	linearised_tab;
	t_list				*node;

	if (linearise_stack(a, &linearised_tab) == -1)
		return (-1);
	sort_tab(&linearised_tab);
	node = a->top;
	while (node)
	{
		node->data = get_rank(linearised_tab.tab,
				node->data,
				linearised_tab.size);
		node = node->next;
	}
	free(linearised_tab.tab);
	return (0);
}
