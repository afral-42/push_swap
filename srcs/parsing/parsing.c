/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounoua <abounoua@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 10:25:15 by abounoua          #+#    #+#             */
/*   Updated: 2026/01/08 16:10:42 by abounoua         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void	update_options(char *arg, int *options)
{
	arg += 2;
	if (!ft_strcmp(arg, "simple"))
		*options = *options | FLAG_SIMPLE;
	else if (!ft_strcmp(arg, "medium"))
		*options = *options | FLAG_MEDIUM;
	else if (!ft_strcmp(arg, "complex"))
		*options = *options | FLAG_COMPLEX;
	else if (!ft_strcmp(arg, "adaptive"))
		*options = *options | FLAG_ADAPTIVE;
	else if (!ft_strcmp(arg, "bench"))
		*options = *options | FLAG_BENCH;
	else
		*options = -1;
}

static int	parse_options(int ac, char **av)
{
	int	options;
	int	modes;
	int	i;

	options = 0;
	i = 1;
	while (i < ac)
	{
		if (!ft_strncmp("--", av[i], 2))
		{
			update_options(av[i], &options);
			if (options == -1)
				return (-1);
		}
		i++;
	}
	modes = options & MASK_MODE;
	if (!modes)
		options |= FLAG_ADAPTIVE;
	if ((modes) & ((modes) - 1))
		options = -1;
	return (options);
} 

int	update_stack(char *stack, t_stack *a)
{
	ssize_t	i;
	int		error;
	int		nb;
	char	**numbers_tab;

	error = 0;
	i = 0;
	numbers_tab = ft_split(stack, ' ');
	if (!numbers_tab)
		return (-1);
	while (numbers_tab[i])
		i++;
	while (--i >= 0)
	{
		nb = ft_atoi_secured((const char *)numbers_tab[i], &error);
		if (error == -1 || push(a, nb) == -1)
			return (free_parsing(a, numbers_tab));
	}
	free_split(numbers_tab);
	return (0);
}

static t_stack	*parse_stack(int ac, char **av)
{
	int		i;
	t_stack	*a;

	i = 1;
	a = init_stack();
	if (!a)
		return (NULL);
	while (i < ac)
	{
		if (ft_strncmp("--", av[i], 2))
		{
			if (update_stack(av[i], a) == -1)
				return (free_stack(a));
		}
		i++;
	}
	return (a);
}

int	parser(int ac, char **av, t_stack **a, int *options)
{
	*options = parse_options(ac, av);
	if (*options == -1)
		return (-1);
	*a = parse_stack(ac, av);
	if (!(*a) || lstcheck_duplicate((*a)->top))
		return (-1);
	if (!compute_disorder(*a))
		return (1);
	return (0);
}

#include <stdio.h>
#include <unistd.h>
void display_active_flags(int options)
{
    printf("\n--- État des Flags ---\n");
    if (options == -1)
    {
        printf("RÉSULTAT : Erreur détectée (options = -1)\n");
        return;
    }

    printf("Valeur brute (int) : %d\n", options);
    
    printf("Modes actifs : ");
    if (options & FLAG_SIMPLE)   printf("[SIMPLE] ");
    if (options & FLAG_MEDIUM)   printf("[MEDIUM] ");
    if (options & FLAG_COMPLEX)  printf("[COMPLEX] ");
    if (options & FLAG_ADAPTIVE) printf("[ADAPTIVE] ");
    
    printf("\nOptions bonus : ");
    if (options & FLAG_BENCH)    printf("[BENCH]");
    else                         printf("[AUCUNE]");
    
    printf("\n----------------------\n\n");
}