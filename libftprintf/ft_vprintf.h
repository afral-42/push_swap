/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebilla <arebilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 09:01:10 by arebilla          #+#    #+#             */
/*   Updated: 2025/11/25 10:50:23 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VPRINTF_H
# define FT_VPRINTF_H

# include <stdarg.h>

# define ERROR -1

int	ft_vprintf(const char *s, va_list vargs);

#endif
