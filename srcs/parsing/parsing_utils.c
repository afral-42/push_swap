/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounoua <abounoua@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 10:33:35 by abounoua          #+#    #+#             */
/*   Updated: 2025/12/17 13:08:34 by abounoua         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	print_list(t_list *lst)
{
	while (lst)
	{
		ft_printf("%d\n", lst->data);
		lst = lst->next;
	}
}

int	ft_atoi_secured(const char *nptr, int *error)
{
	int		sign;
	long	n;

	sign = 1;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	n = 0;
	while (ft_isdigit(*nptr) && n < 2147483647 && n > -2147483648)
		n = 10 * n + *nptr++ - '0';
    if ((*nptr && !ft_isdigit(*nptr)) || (n > 2147483647 || n < -2147483648))
    {
		*error = -1;
		return (0);
	}
	return ((int)(n * sign));
}

void    *free_split(char **tab)
{
    size_t	i;

	i = 0;
    while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}