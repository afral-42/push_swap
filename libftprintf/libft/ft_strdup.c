/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebilla <arebilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:55:10 by arebilla          #+#    #+#             */
/*   Updated: 2025/11/18 10:28:25 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	l_s;
	char	*dup;

	l_s = ft_strlen(s);
	dup = malloc(l_s + 1);
	if (!dup)
		return (NULL);
	ft_memcpy(dup, s, l_s + 1);
	return (dup);
}
