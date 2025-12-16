/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebilla <arebilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:51:59 by arebilla          #+#    #+#             */
/*   Updated: 2025/11/12 11:58:35 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	char	*p_s;

	if (!s || !f)
		return ;
	p_s = s;
	while (*p_s)
	{
		f((unsigned int)(p_s - s), p_s);
		p_s++;
	}
}
