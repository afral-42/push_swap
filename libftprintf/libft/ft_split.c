/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebilla <arebilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 17:15:08 by arebilla          #+#    #+#             */
/*   Updated: 2025/11/17 18:19:23 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static const char	*move_to_next_word(char const *s, char c)
{
	while (*s && *s == c)
		s++;
	return (s);
}

static const char	*move_to_next_sep(char const *s, char c)
{
	while (*s && *s != c)
		s++;
	return (s);
}

static size_t	count_words(char const *s, char c)
{
	size_t	count;

	count = 0;
	s = move_to_next_word(s, c);
	while (*s)
	{
		count++;
		s = move_to_next_sep(s, c);
		s = move_to_next_word(s, c);
	}
	return (count);
}

static void	*free_split(char **split, size_t	l_split)
{
	char	**p_split;

	p_split = split;
	while (l_split)
	{
		free(*p_split);
		p_split++;
		l_split--;
	}
	free(split);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char		**split;
	char		**p_split;
	const char	*p_s;
	size_t		nb_words;

	if (!s)
		return (NULL);
	nb_words = count_words(s, c);
	split = ft_calloc(sizeof(*split), nb_words + 1);
	if (!split)
		return (NULL);
	p_split = split;
	s = move_to_next_word(s, c);
	while (nb_words--)
	{
		p_s = move_to_next_sep(s, c);
		*p_split = ft_substr(s, 0, p_s - s);
		if (!(*p_split))
			return (free_split(split, p_split - split));
		p_split++;
		s = move_to_next_word(p_s, c);
	}
	*p_split = NULL;
	return (split);
}
