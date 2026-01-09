/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounoua <abounoua@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 10:39:48 by abounoua          #+#    #+#             */
/*   Updated: 2026/01/08 18:03:26 by abounoua         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "list.h"
# include "libft.h"
# include "ft_printf.h"
# include "list.h"
# include "stack.h"
# include "operations.h"
# include <unistd.h>

typedef enum e_flags
{
	FLAG_SIMPLE = 1,
    FLAG_MEDIUM = 1 << 1,
    FLAG_COMPLEX = 1 << 2,
    FLAG_ADAPTIVE = 1 << 3,
    FLAG_BENCH = 1 << 4,
    FLAG_DEBUG = 1 << 5,
    MASK_MODE = FLAG_SIMPLE | FLAG_MEDIUM | FLAG_COMPLEX | FLAG_ADAPTIVE
}	t_flags;

int		ft_atoi_secured(const char *nptr, int *error);
void	print_list(t_list *lst);
int	    ft_strcmp(char *s1, char *s2);
int		free_parsing(t_stack *a, char **tab);
void    *free_split(char **tab);
int	    parser(int ac, char **av, t_stack **a, int *options);
void	display_active_flags(int options);
void	print_bench_info(double disorder, int options, t_ops_counter *ops_counter);
char	**split_args(char const *s, char *charset);

#endif
