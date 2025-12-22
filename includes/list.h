/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounoua <abounoua@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:25:49 by abounoua          #+#    #+#             */
/*   Updated: 2025/12/18 14:25:08 by abounoua         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include <stdlib.h>

typedef struct s_list
{
	struct s_list	*next;
	struct s_list	*prev;
	int				data;
}	t_list;

t_list	*lstnew(int data);
void	lstadd_front(t_list **lst, t_list *node);
void	*free_lst(t_list *lst);
int		lstcheck_duplicate(t_list *lst);
void	lst_move_head(t_list **dest, t_list **src);

#endif
