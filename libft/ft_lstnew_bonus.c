/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaciri- <hnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:25:31 by hnaciri-          #+#    #+#             */
/*   Updated: 2024/01/03 19:08:38 by hnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_relations	*ft_lstnew(char *lRoom, char *rRoom)
{
	t_relations	*new;

	new = malloc (sizeof(t_relations));
	if (new == 0)
		return (0);
	new->lRoom = ft_strdup(lRoom);
	new->rRoom = ft_strdup(rRoom);
	new->next = 0;
	return (new);
}
