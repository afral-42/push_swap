/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebilla <arebilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 12:26:29 by arebilla          #+#    #+#             */
/*   Updated: 2025/11/17 18:47:09 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*p;

	if (!(char)c)
		return ((char *)(s + ft_strlen(s)));
	p = ft_strchr(s, c);
	if (!p)
		return (NULL);
	while (p)
	{
		s = p;
		p = ft_strchr(s + 1, c);
	}
	return ((char *)s);
}
