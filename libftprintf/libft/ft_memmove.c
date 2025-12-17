/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebilla <arebilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 09:53:37 by arebilla          #+#    #+#             */
/*   Updated: 2025/11/18 10:23:07 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*p_dest_char;
	char	*p_src_char;

	if (!n || dest == src)
		return (dest);
	if (dest > src)
	{
		p_dest_char = ((char *)dest) + n - 1;
		p_src_char = ((char *)src) + n - 1;
		while (n--)
			*p_dest_char-- = *p_src_char--;
	}
	else if (src >= dest + sizeof(size_t))
		ft_memcpy(dest, src, n);
	else
	{
		p_dest_char = (char *)dest;
		p_src_char = (char *)src;
		while (n--)
			*p_dest_char++ = *p_src_char++;
	}
	return (dest);
}
