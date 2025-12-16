/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_value_helpers1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebilla <arebilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 10:55:39 by arebilla          #+#    #+#             */
/*   Updated: 2025/11/25 17:49:16 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"
#include "libft.h"

ssize_t	format_str(t_specifiers specifiers)
{
	if (!specifiers.arg.s)
		return (out("(null)", 6));
	return (out(specifiers.arg.s, ft_strlen(specifiers.arg.s)));
}

ssize_t	format_chr(t_specifiers specifiers)
{
	return (out(&(specifiers.arg.c), 1));
}
