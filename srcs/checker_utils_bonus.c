/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounoua <abounoua@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 16:26:55 by abounoua          #+#    #+#             */
/*   Updated: 2026/01/15 18:57:06 by abounoua         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "operations.h"
#include "libft.h"
#include "stack.h"

static int	ft_strcmp(char *s1, char *s2)
{
    int i;

    i = 0;
    while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
        i++;
    return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

static int	free_all(t_stack *b, t_ops_counter *ops_counter)
{
	if (b)
		free_stack(b);
	if (ops_counter)
		free(ops_counter);
	return (-1);
}

static int	apply_ops(t_stack *a, t_stack *b, char *op, t_ops_counter *ops_counter)
{
	if (!ft_strcmp(op, "sa\n"))
		swap_a(a, ops_counter);
	else if (!ft_strcmp(op, "sb\n"))
		swap_b(b, ops_counter);
	else if (!ft_strcmp(op, "ss\n"))
		swap_both(a, b, ops_counter);
	else if (!ft_strcmp(op, "pa\n"))
		push_a(a, b, ops_counter);
	else if (!ft_strcmp(op, "pb\n"))
		push_b(b, a, ops_counter);
	else if (!ft_strcmp(op, "ra\n"))
		rotate_a(a, ops_counter);
	else if (!ft_strcmp(op, "rb\n"))
		rotate_b(b, ops_counter);
	else if (!ft_strcmp(op, "rr\n"))
		rotate_both(a, b, ops_counter);
	else if (!ft_strcmp(op, "rra\n"))
		reverse_rotate_a(a, ops_counter);
	else if (!ft_strcmp(op, "rrb\n"))
		reverse_rotate_b(b, ops_counter);
	else if (!ft_strcmp(op, "rrr\n"))
		reverse_rotate_both(a, b, ops_counter);
	else
		return (-1);
	return (0);
}

static int	read_and_apply_ops(t_stack *a, t_stack *b, t_ops_counter *ops_counter)
{
	char *op;

	op = get_next_line(0);
	while (op)
	{
		if (apply_ops(a, b, op, ops_counter) == -1)
		{
			free(op);
			return (-1);
		}
		free(op);
		op = get_next_line(0);
	}
	return (0);
}

int	checker(t_stack *a)
{
	t_stack			*b;
	t_ops_counter	*ops_counter;
	double			disorder;
	int				is_b_empty;
	
	b = init_stack();
	if (!b)
		return (-1);
	ops_counter = new_ops_counter();
	if (!ops_counter)
		return (free_all(b, NULL));
	ops_counter->print_flag = 0;
	if (read_and_apply_ops(a, b, ops_counter) == -1)
		return (free_all(b, ops_counter));
	disorder = compute_disorder(a);
	is_b_empty = b->top == NULL;
	free_all(b, ops_counter);
	if (!disorder && is_b_empty)
		return (0);
	return (1);
}
