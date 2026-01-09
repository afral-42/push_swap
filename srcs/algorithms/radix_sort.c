/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounoua <abounoua@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 11:33:36 by abounoua          #+#    #+#             */
/*   Updated: 2026/01/08 18:22:46 by abounoua         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "algorithms.h"
#include "list.h"


typedef struct	s_linearised_tab
{
	int		*tab;
	size_t	size;
}	t_linearised_tab;


int	linearise_stack(t_stack *a, t_linearised_tab *linearised_tab)
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

void	sort_tab(t_linearised_tab *linearised_tab)
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

static int get_rank(int *sorted_tab, int value, size_t size)
{
    size_t i;

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
	size_t				i;
	
	if (linearise_stack(a, &linearised_tab) == -1)
		return (-1);
	sort_tab(&linearised_tab);
	node = a->top;
	i = 0;
	while (node)
	{
		node->data = get_rank(linearised_tab.tab,
								node->data, 
								linearised_tab.size);
		node = node->next;
		i++;
	}
	free(linearised_tab.tab);
	return (0);
}

void	split_by_bit(t_stack *a, t_stack *b, unsigned short bit, t_ops_counter *ops)
{
	size_t	i;
	size_t	stack_size;
	
	i = 0;
	stack_size = a->size;
	while (i < stack_size)
	{
		if ((a->top->data >> bit) & 1)
			rotate_a(a, ops);
		else
			push_b(b, a, ops);
		i++;
	}
}

void	operate_radix_sort(t_stack *a, t_stack *b, t_ops_counter *ops)
{
	unsigned short	bit;

	bit = 0;
	while (bit < 32)
	{
		if (!compute_disorder(a))
			break;
		split_by_bit(a, b, bit, ops);
		transfer_stack(a, b, ops, &push_a);
		bit++;
	}
}

t_ops_counter	*radix_sort(t_stack *a)
{
	t_ops_counter	*ops;
	t_stack			*b;

	ops = new_ops_counter();
	if (!ops)
		return (NULL);
	b = init_stack();
	if (!b)
	{
		free(ops);
		return (NULL);
	}
	if (compress_stack(a) == -1)
	{
		free(ops);
		free_stack(b);
		return (NULL);
	}
	operate_radix_sort(a, b, ops);
	free_stack(b);
	return (ops);
}
