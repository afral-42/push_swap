/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounoua <abounoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 16:12:08 by abounoua          #+#    #+#             */
/*   Updated: 2025/12/16 13:23:15 by arebilla         ###   ########.fr       */
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

t_list	*lstnew(int data);
void	lstadd_front(t_list **lst, t_list *node);
void	lst_delone(t_list *node);
void	*free_lst(t_list *lst);
void	lstdel_front(t_list **lst);
void	lst_rotate(t_list **lst);
void	lst_reverse_rotate(t_list **lst);
void	lst_swap_head_nodes(t_list **lst);

int		pop(t_stack *stack);
int		stack_is_empty(t_stack *stack);
void	push(t_stack *stack, int data);

#endif
