/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounoua <abounoua@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 10:33:35 by abounoua          #+#    #+#             */
/*   Updated: 2025/12/17 10:35:12 by abounoua         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "list.h"
#include "stack.h"

void	print_list(t_list *lst)
{
	while (lst)
	{
		ft_printf("%d\n", lst->data);
		lst = lst->next;
	}
}

