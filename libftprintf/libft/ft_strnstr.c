/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebilla <arebilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 15:23:12 by arebilla          #+#    #+#             */
/*   Updated: 2025/11/18 10:22:39 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	l_little;
	size_t	l_big;

	l_little = ft_strlen(little);
	if (!l_little)
		return ((char *)big);
	if (!len)
		return (NULL);
	l_big = ft_strlen(big);
	if (l_big > len)
		l_big = len;
	while (l_big >= l_little)
	{
		if (ft_strncmp(big, little, l_little) == 0)
			return ((char *)big);
		big++;
		l_big--;
	}
	return (NULL);
}
