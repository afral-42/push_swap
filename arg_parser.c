/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebilla <arebilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 16:32:13 by arebilla          #+#    #+#             */
/*   Updated: 2025/12/16 16:42:01 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack	*parse_stack(int	ac, char **av)
{
	t_stack	*stack;
	int		nb;
	int		i;
	int		size;

	stack = init_stack();
	if (!stack)
		return (NULL);
	i = 1;
	while (str_isdigit(av[i]))
		i++;
	i--;
	while (i > 0)
	{
		push_st(stack, atoi(av[i])); //TODO: replace with libft
		i--;
	}
	return (stack);
}
