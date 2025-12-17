/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prefix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebilla <arebilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:22:14 by arebilla          #+#    #+#             */
/*   Updated: 2025/11/25 17:40:56 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

int	get_prefix_size(t_specifiers specifiers)
{
	if (specifiers.type == PTR && specifiers.arg.p != 0)
		return (2);
	if (specifiers.type == INT && specifiers.arg.i < 0)
		return (1);
	return (0);
}

ssize_t	prefix(t_specifiers specifiers)
{
	if (specifiers.type == PTR && specifiers.arg.p != 0)
		return (out("0x", 2));
	if (specifiers.type == INT && specifiers.arg.i < 0)
		return (out("-", 1));
	return (0);
}
