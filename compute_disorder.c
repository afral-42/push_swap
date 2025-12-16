/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebilla <arebilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 16:10:39 by arebilla          #+#    #+#             */
/*   Updated: 2025/12/16 16:10:40 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

double	compute_disorder(t_stack *stack)
{
	int		mistakes;
	int		total_pairs;
	t_list	*node1;
	t_list	*node2;

	if (!stack->top || !stack->top->next)
		return (0);
	mistakes = 0;
	total_pairs = 0;
	node1 = stack->top;
	while (node1)
	{
		node2 = node1->next;
		while (node2)
		{
			total_pairs++;
			if (node1->data > node2->data)
				mistakes++;
			node2 = node2->next;
		}
		node1 = node1->next;
	}
	return ((double)mistakes / total_pairs);
}
