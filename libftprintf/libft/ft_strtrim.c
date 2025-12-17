/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebilla <arebilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:17:04 by arebilla          #+#    #+#             */
/*   Updated: 2025/11/17 18:06:30 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	const char	*p_begin;
	const char	*p_end;
	char		*trim;

	if (!s1 || !set)
		return (NULL);
	p_begin = s1;
	p_end = s1 + ft_strlen(s1);
	while (*p_begin && ft_strchr(set, *p_begin))
		p_begin++;
	while (p_end > p_begin && ft_strchr(set, *(p_end - 1)))
		p_end--;
	trim = ft_substr(p_begin, 0, p_end - p_begin);
	if (!trim)
		return (NULL);
	return (trim);
}
