/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaciri- <hnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 14:55:36 by hnaciri-          #+#    #+#             */
/*   Updated: 2024/01/03 18:56:42 by hnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_relations **lst, t_relations *new)
{
	t_relations	*p;

	if (lst && new)
	{
		p = *lst;
		new->next = 0;
		if (p == 0)
		{
			*lst = new;
			return ;
		}
		while (p->next != 0)
			p = p->next;
		p->next = new;
	}
}
