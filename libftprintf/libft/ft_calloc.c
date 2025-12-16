/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebilla <arebilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:46:32 by arebilla          #+#    #+#             */
/*   Updated: 2025/11/12 14:16:52 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	mult_ok(size_t x, size_t y)
{
	size_t	p;

	p = x * y;
	return (!x || y == p / x);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	len;
	void	*ptr;

	if (!mult_ok(nmemb, size))
		return (NULL);
	len = nmemb * size;
	ptr = malloc(len);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, len);
	return (ptr);
}
