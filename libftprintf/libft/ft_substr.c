/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebilla <arebilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:16:50 by arebilla          #+#    #+#             */
/*   Updated: 2025/11/17 18:05:26 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*sub;

	if (!s)
		return (NULL);
	if (ft_memchr(s, 0, start))
		return (ft_strdup(""));
	s += start;
	if (ft_memchr(s, 0, len))
		return (ft_strdup(s));
	sub = malloc(len + 1);
	if (!sub)
		return (NULL);
	ft_memcpy(sub, s, len);
	sub[len] = '\0';
	return (sub);
}
