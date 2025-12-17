/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounoua <abounoua@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 10:25:15 by abounoua          #+#    #+#             */
/*   Updated: 2025/12/17 13:11:54 by abounoua         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	parse_options(char *args)
{
	args++;
	return (0);
}

t_stack	*parse_stack(char *stack)
{
	t_stack	*a;
	char	**numbers_tab;
	int		error;
	int		nb;
	ssize_t	i;

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
		if (error == -1)
		{
			free_stack(a);
			return ((t_stack *)free_split(numbers_tab));
		}
		push(a, nb); // Peut échouer -> checker la valeur de retour
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