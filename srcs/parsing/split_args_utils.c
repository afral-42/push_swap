/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_args_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounoua <abounoua@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 18:02:49 by abounoua          #+#    #+#             */
/*   Updated: 2026/01/13 10:35:11 by abounoua         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int	is_charset(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

const char	*move_to_next_word(char const *s, char *charset)
{
	while (*s && is_charset(*s, charset))
		s++;
	return (s);
}

const char	*move_to_next_sep(char const *s, char *charset)
{
	while (*s && !is_charset(*s, charset))
		s++;
	return (s);
}

size_t	count_words(char const *s, char *charset)
{
	size_t	count;

	count = 0;
	s = move_to_next_word(s, charset);
	while (*s)
	{
		count++;
		s = move_to_next_sep(s, charset);
		s = move_to_next_word(s, charset);
	}
	return (count);
}
