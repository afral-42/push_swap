/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounoua <abounoua@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 16:17:39 by abounoua          #+#    #+#             */
/*   Updated: 2026/01/16 11:20:44 by abounoua         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "algorithms.h"
#include "operations.h"
#include "ft_printf.h"

int	quicksort_b_and_push_a(t_stack *a, t_stack *b, size_t partition,
			t_ops_counter *ops);

void	partition_a(t_stack *a, t_stack *b,
	t_partition *partition_infos, t_ops_counter *ops)
{
	size_t	i;

	i = 0;
	while (i < partition_infos->partition_size)
	{
		if (a->top->data < partition_infos->mediane)
		{
			push_b(b, a, ops);
			partition_infos->lower_partition_size++;
		}
		else
		{
			rotate_a(a, ops);
			partition_infos->upper_partition_size++;
		}
		i++;
	}
	if (partition_infos->upper_partition_size != a->size)
	{
		i = 0;
		while (i++ < partition_infos->upper_partition_size)
			reverse_rotate_a(a, ops);
	}
}

void	partition_b(t_stack *a, t_stack *b,
	t_partition *partition_infos, t_ops_counter *ops)
{
	size_t	i;

	i = 0;
	while (i < partition_infos->partition_size)
	{
		if (b->top->data >= partition_infos->mediane)
		{
			push_a(a, b, ops);
			partition_infos->upper_partition_size++;
		}
		else
		{
			rotate_b(b, ops);
			partition_infos->lower_partition_size++;
		}
		i++;
	}
	if (partition_infos->lower_partition_size != b->size)
	{
		i = 0;
		while (i++ < partition_infos->lower_partition_size)
			reverse_rotate_b(b, ops);
	}
}

int	quicksort_a(t_stack *a, t_stack *b, size_t partition_size,
			t_ops_counter *ops)
{
	t_partition	partition_infos;

	if (partition_size <= 3)
	{
		process_base_case_a(a, b, partition_size, ops);
		return (0);
	}
	if (get_mediane(a, &(partition_infos.mediane), partition_size) == -1)
		return (-1);
	partition_infos.lower_partition_size = 0;
	partition_infos.upper_partition_size = 0;
	partition_infos.partition_size = partition_size;
	partition_a(a, b, &partition_infos, ops);
	if (quicksort_a(a, b, partition_infos.upper_partition_size, ops) == -1)
		return (-1);
	if (quicksort_b_and_push_a(a, b, partition_infos.lower_partition_size, ops) == -1)
		return (-1);
	return (0);
}

int	quicksort_b_and_push_a(t_stack *a, t_stack *b, size_t partition_size,
			t_ops_counter *ops)
{
	t_partition	partition_infos;

	if (partition_size <= 3)
	{
		process_base_case_b(b, a, partition_size, ops);
		return (0);
	}
	if (get_mediane(b, &(partition_infos.mediane), partition_size) == -1)
		return (-1);
	partition_infos.lower_partition_size = 0;
	partition_infos.upper_partition_size = 0;
	partition_infos.partition_size = partition_size;
	partition_b(a, b, &partition_infos, ops);
	if (quicksort_a(a, b, partition_infos.upper_partition_size, ops) == -1)
		return (-1);
	if (quicksort_b_and_push_a(a, b, partition_infos.lower_partition_size, ops) == -1)
		return (-1);
	return (0);
}

void	quick_sort(t_stack *a, t_ops_counter *ops)
{
	t_stack	*b;

	b = init_stack();
	if (!b)
	{
		free(ops);
		return ;
	}
	if (quicksort_a(a, b, a->size, ops) == -1)
	{
		free(ops);
		free_stack(b);
		free_stack(a);
		exit(1);
	}
	free_stack(b);
}
