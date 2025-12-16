/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifiers_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebilla <arebilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 17:28:46 by arebilla          #+#    #+#             */
/*   Updated: 2025/11/25 17:28:51 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils_bonus.h"

void	set_precision(t_specifiers *specifiers, int precision)
{
	specifiers->precision = precision;
	specifiers->precision_set = 1;
}

t_specifiers	new_specifiers(void)
{
	t_specifiers	specifiers;
	size_t			i;

	i = 0;
	while (i < 128)
		specifiers.flags[i++] = 0;
	specifiers.width = 0;
	specifiers.precision = 1;
	specifiers.precision_set = 0;
	specifiers.to_upper = 0;
	specifiers.type = UNDEFINED;
	specifiers.arg.i = 0;
	return (specifiers);
}
