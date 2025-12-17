/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebilla <arebilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 09:44:50 by arebilla          #+#    #+#             */
/*   Updated: 2025/11/18 10:24:06 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*smap;
	char			*p_smap;
	size_t			l_s;

	if (!s || !f)
		return (NULL);
	l_s = ft_strlen(s);
	smap = malloc(l_s + 1);
	if (!smap)
		return (NULL);
	p_smap = smap;
	while (*s)
	{
		*p_smap = f((unsigned int)(p_smap - smap), *s);
		s++;
		p_smap++;
	}
	*p_smap = '\0';
	return (smap);
}
