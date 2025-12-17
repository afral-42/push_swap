/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounoua <abounoua@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 10:25:15 by abounoua          #+#    #+#             */
/*   Updated: 2025/12/17 17:50:32 by abounoua         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	parse_options(char *args)
{
	args++;
	return (0);
}

static void	*free_parsing(t_stack *a, char **tab)
{
    size_t	i;

	i = 0;
    while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	free_stack(a);
	return (NULL);
}
t_stack	*parse_stack(char *stack)
{
	t_stack	*a;
	ssize_t	i;
	int		error;
	int		nb;
	char	**numbers_tab;
	
	a = init_stack();
	if (!a)
		return (NULL);
	error = 0;
	i = 0;
	numbers_tab = ft_split(stack, ' ');
	while (numbers_tab[i])
		i++;
	while (--i >= 0)
	{
		nb = ft_atoi_secured((const char *)numbers_tab[i], &error);
		if (error == -1 || push(a, nb) == -1)
			return (free_parsing(a, numbers_tab));
	}
	return (a);
}

// To do
// Écrire les tests unitaires
// Sécuriser la fonction push pour retourner -1 et stopper le programme si c'est le cas

void	parsing(char *stack, char *args, t_stack **a, int *options)
{
	if (!stack || !args)
		return ;
	*a = parse_stack(stack);
	*options = parse_options(args);
}

int main(int ac, char **av)
{
    t_stack		*a;
	t_stack		*b;
	int			options;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (1);
	if (ac > 3)
	{
		write(2, "Error\n", 6);
		return (1);
    }	
	parsing(av[1], av[2], &a, &options);
	if (!a || options == -1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	print_list(a->top);
	return (0);
}