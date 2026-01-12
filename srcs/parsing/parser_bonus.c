/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebilla <arebilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 09:04:41 by arebilla          #+#    #+#             */
/*   Updated: 2026/01/12 09:06:09 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	parser_bonus(int ac, char **av, t_stack **a, int *options)
{
	if (*options == -1)
		return (-1);
	*a = parse_stack(ac, av);
	if (!(*a) || lstcheck_duplicate((*a)->top))
		return (-1);
	if (!compute_disorder(*a))
		return (1);
	return (0);
}
