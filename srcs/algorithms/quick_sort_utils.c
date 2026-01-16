/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounoua <abounoua@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 10:46:54 by abounoua          #+#    #+#             */
/*   Updated: 2026/01/16 11:20:38 by abounoua         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "algorithms.h"
#include "operations.h"
#include "ft_printf.h"

static int	linearise_tab(t_stack *a, t_linearised_tab *linearised_tab,
	size_t partition)
{
	size_t	i;
	t_list	*node;

	linearised_tab->tab = malloc(sizeof(int) * partition);
	if (!(linearised_tab->tab))
		return (-1);
	node = a->top;
	i = 0;
	while (node && i < partition)
	{
		(linearised_tab->tab)[i] = node->data;
		i++;
		node = node->next;
	}
	linearised_tab->size = i;
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

int	get_mediane(t_stack *a, int *mediane, size_t partition)
{
	t_linearised_tab	linearised_tab;

	if (linearise_tab(a, &linearised_tab, partition) == -1)
		return (-1);
	sort_tab(&linearised_tab);
	*mediane = (linearised_tab.tab)[linearised_tab.size / 2];
	free(linearised_tab.tab);
	return (0);
}

void	process_base_case_a(t_stack *a, t_stack *b, size_t partition,
	t_ops_counter *ops)
{
	if (partition == 1)
		return ;
	else if (partition == 2)
	{
		if (a->top->data > a->top->next->data)
			swap_a(a, ops);
	}
	else
	{
		if (a->top->data > a->top->next->data)
			swap_a(a, ops);
		if (a->top->next->data > a->top->next->next->data)
		{
			push_b(b, a, ops);
			swap_a(a, ops);
			push_a(a, b, ops);
		}
		if (a->top->data > a->top->next->data)
			swap_a(a, ops);
	}
}

void	process_base_case_b(t_stack *b, t_stack *a, size_t partition,
	t_ops_counter *ops)
{
	if (partition == 1)
		return ;
	else if (partition == 2)
	{
		if (b->top->data < b->top->next->data)
			swap_b(b, ops);
	}
	else
	{
		if (b->top->data < b->top->next->data)
			swap_b(b, ops);
		if (b->top->next->data < b->top->next->next->data)
		{
			push_a(a, b, ops);
			swap_b(b, ops);
			push_b(b, a, ops);
		}
		if (b->top->data < b->top->next->data)
			swap_b(b, ops);
	}
	while (partition)
	{
		push_a(a, b, ops);
		partition--;
	}
}
