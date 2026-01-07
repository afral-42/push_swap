/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounoua <abounoua@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 16:17:39 by abounoua          #+#    #+#             */
/*   Updated: 2026/01/07 19:23:49 by abounoua         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "algorithms.h"
#include "operations.h"


#include "ft_printf.h"


void    quicksort_b(t_stack *a, t_stack *b, size_t partition, t_ops_counter *ops);

typedef struct	s_linearised_tab
{
	int		*tab;
	size_t	size;
}	t_linearised_tab;

void	print_tab(t_linearised_tab *linearised_tab)
{
	int		*tab;
	size_t	i;

	tab = linearised_tab->tab;
	i = 0;
	while (i < linearised_tab->size)
	{
		ft_printf("%d->", tab[i]);
		i++;
	}
	ft_printf(" END");
}

int	linearise_tab(t_stack *a, t_linearised_tab *linearised_tab, size_t partition)
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

void    process_base_case_b(t_stack *b, t_stack *a, size_t partition, 
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
void    quicksort_a(t_stack *a, t_stack *b, size_t partition, t_ops_counter *ops)
{
    int     mediane;
    size_t  i;
    size_t  rotated_count;
    size_t  pushed_count;

    if (partition <= 3)
    {
        process_base_case_a(a, b, partition, ops);
        return ;
    }
    if (get_mediane(a, &mediane, partition) == -1)
        return ;
    i = 0;
    rotated_count = 0;
    pushed_count = 0;
    while (i < partition)
    {
        if (a->top->data < mediane) 
        {
            push_b(b, a, ops);
            pushed_count++;
        }
        else 
        {
            rotate_a(a, ops);
            rotated_count++;
        }
        i++;
    }
    if (rotated_count != a->size)
    {
        i = 0;
        while (i < rotated_count)
        {
            reverse_rotate_a(a, ops);
            i++;
        }
    }
    quicksort_a(a, b, rotated_count, ops);
    quicksort_b(a, b, pushed_count, ops);
}

void    quicksort_b(t_stack *a, t_stack *b, size_t partition, t_ops_counter *ops)
{
    int     mediane;
    size_t  i;
    size_t  rotated_count;
    size_t  pushed_count;

    if (partition <= 3)
    {
        process_base_case_b(b, a, partition, ops);
        return ;
    }
    if (get_mediane(b, &mediane, partition) == -1)
        return ;

    i = 0;
    rotated_count = 0;
    pushed_count = 0;
    while (i < partition)
    {
        if (b->top->data >= mediane)
        {
            push_a(a, b, ops);
            pushed_count++;
        }
        else 
        {
            rotate_b(b, ops);
            rotated_count++;
        }
        i++;
    }
    if (rotated_count != b->size)
    {
        i = 0;
        while (i < rotated_count)
        {
            reverse_rotate_b(b, ops);
            i++;
        }
    }
    quicksort_a(a, b, pushed_count, ops);
    quicksort_b(a, b, rotated_count, ops);
}

t_ops_counter	*quick_sort(t_stack *a)
{
	t_stack				*b;
	t_ops_counter		*ops;

	ops = new_ops_counter();
	if (!ops)
		return (NULL);
	b = init_stack();
	if (!b)
	{
		free(ops);
		return (NULL);
	}
	quicksort_a(a, b, a->size, ops);
	free_stack(b);
	return (ops);
}
