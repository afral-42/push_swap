/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounoua <abounoua@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 11:50:11 by abounoua          #+#    #+#             */
/*   Updated: 2026/01/07 11:17:01 by abounoua         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "algorithms.h"
#include "parsing.h"

size_t	find_max_index(t_stack *b, int *maximum)
{
    t_list  *node;
	size_t	index;
    size_t  i;
	int		max;

    node = b->top;
	max = node->data;
	i = 0;
	index = 0;
    while (node)
	{
		if (node->data > max)
		{
			max = node->data;
			index = i;
		}
		node = node->next;
		i++;
	}
	*maximum = max;
	return (index);
}

int	fill_buckets(t_stack *a, t_stack *b, size_t buckets_number,
	size_t	bucket_size, int min)
{
	size_t	rotations_count;
	size_t	stack_size;
	size_t	bucket_index;
	int		count;

	count = 0;
	bucket_index = 0;
	while (bucket_index < buckets_number)
	{
		rotations_count = 0;
		stack_size = a->size;
		while (rotations_count < stack_size)
		{
			if (a->top->data <= (int)(min + (bucket_index + 1) * bucket_size))
				count += push_b(b, a);
			else
				count += rotate_a(a);	
			rotations_count++;
		}
		bucket_index++;
	}
	return (count);
}

int	empty_buckets(t_stack *a, t_stack *b)
{
	size_t	max_index;
	int		max;
	int		(*action[2])(t_stack *);
	int		count;
	
	count = 0;
	action[0] = &reverse_rotate_b;
	action[1] = &rotate_b;
	while (b->top)
	{
		max_index = find_max_index(b, &max);
		while (b->top->data != max)
			count += action[max_index <= b->size / 2](b);
		count += push_a(a, b);
	}
	return (count);
}

int	bucket_sort(t_stack *a)
{
	t_stack	*b;
	size_t	buckets_number;
	size_t	bucket_size;
	int		min;
	int		count;

	b = init_stack();
	if (!b)
		return (-1);
	min = lstget_min(a->top);
	buckets_number = ft_sqrt(a->size);
	bucket_size = (lstget_max(a->top) - min + 1) / buckets_number + 1;
	count = 0;
	count += fill_buckets(a, b, buckets_number, bucket_size, min);
	count += empty_buckets(a, b);
	free_stack(b);
	return (count);
}

// On calcule racine de n pour avoir le nombre de seaux

// On calcule la size d'un seau : trouver le min + trouver le max pour avoir la range (min - max) qu'on divise par racine n pour avoir la taille d'un seau

// On parcourt la stack racine de n fois (une fois par seau) et pour chaque élement on le compare à max - ((numéro de seau + 1) * taille d'un seau) : si il est supérieur on le push dans b sinon on le skip
// Complexité théorique : O(n√n)

// B est grossièrement triée dans l'ordre décroissant

// On parcourt B seau par seau (racine de n) jusqu'à trouver le max du seau qu'on push dans A 
// Complexité théorique : O(n√n)

// Complexité théorique finale : O(n√n + n√n) = O(2(n√n)) = O(n√n)
