/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounoua <abounoua@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 10:39:48 by abounoua          #+#    #+#             */
/*   Updated: 2025/12/17 11:28:05 by abounoua         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "libft.h"
#include "ft_printf.h"
#include "list.h"
#include "stack.h"
#include <unistd.h>

typedef enum e_flags
{
	SIMPLE = 1,
    MEDIUM = 1 << 1,
    COMPLEX = 1 << 2,
    ADAPTIVE = 1 << 3, 
    BENCH = 1 << 4
}	t_flags;

void    *free_split(char **tab);
int		ft_atoi_secured(const char *nptr, int *error);
void	print_list(t_list *lst);