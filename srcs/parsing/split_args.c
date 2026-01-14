/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounoua <abounoua@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 10:22:16 by abounoua          #+#    #+#             */
/*   Updated: 2026/01/13 10:33:35 by abounoua         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "parsing.h"

static void	*free_all(char **split, size_t l_split)
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

char	**split_args(char const *s, char *charset)
{
	char		**split;
	char		**p_split;
	const char	*p_s;
	size_t		nb_words;

	if (!s)
		return (NULL);
	nb_words = count_words(s, charset);
	split = ft_calloc(sizeof(*split), nb_words + 1);
	if (!split)
		return (NULL);
	p_split = split;
	s = move_to_next_word(s, charset);
	while (nb_words--)
	{
		p_s = move_to_next_sep(s, charset);
		*p_split = ft_substr(s, 0, p_s - s);
		if (!(*p_split))
			return (free_all(split, p_split - split));
		p_split++;
		s = move_to_next_word(p_s, charset);
	}
	*p_split = NULL;
	return (split);
}
