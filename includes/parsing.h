/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounoua <abounoua@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 10:39:48 by abounoua          #+#    #+#             */
/*   Updated: 2025/12/18 13:33:50 by abounoua         ###   ########lyon.fr   */
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
	FLAG_SIMPLE = 1,
    FLAG_MEDIUM = 1 << 1,
    FLAG_COMPLEX = 1 << 2,
    FLAG_ADAPTIVE = 1 << 3,
    FLAG_BENCH = 1 << 4,
    MASK_MODE = FLAG_SIMPLE | FLAG_MEDIUM | FLAG_COMPLEX | FLAG_ADAPTIVE
}	t_flags;

int		ft_atoi_secured(const char *nptr, int *error);
void	print_list(t_list *lst);
int	    ft_strcmp(char *s1, char *s2);
void	*free_parsing(t_stack *a, char **tab);
void    *free_split(char **tab);