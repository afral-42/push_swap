/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebilla <arebilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:24:49 by arebilla          #+#    #+#             */
/*   Updated: 2025/11/18 10:25:14 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	l_s1;
	size_t	l_s2;
	size_t	l_join;
	char	*join;

	if (!s1 || !s2)
		return (NULL);
	l_s1 = ft_strlen(s1);
	l_s2 = ft_strlen(s2);
	l_join = l_s1 + l_s2;
	join = malloc(l_join + 1);
	if (!join)
		return (NULL);
	ft_memcpy(join, s1, l_s1);
	ft_memcpy(join + l_s1, s2, l_s2);
	join[l_join] = '\0';
	return (join);
}
