/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounoua <abounoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 16:12:08 by abounoua          #+#    #+#             */
/*   Updated: 2025/12/12 18:55:46 by abounoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdlib.h>

typedef	struct s_list
{
	struct s_list	*next;
	struct s_list	*prev;
	int				data;
}	t_list;

typedef struct	s_stack
{
	t_list	*top;
	size_t	size;
}	t_stack;

#endif