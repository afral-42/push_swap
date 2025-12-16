/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifiers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebilla <arebilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:04:22 by arebilla          #+#    #+#             */
/*   Updated: 2025/11/25 17:39:52 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

t_specifiers	new_specifiers(void)
{
	t_specifiers	specifiers;

	specifiers.to_upper = 0;
	specifiers.type = UNDEFINED;
	specifiers.arg.i = 0;
	return (specifiers);
}
