/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaciri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:35:06 by hnaciri-          #+#    #+#             */
/*   Updated: 2021/11/09 12:52:26 by hnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char static	*ft_copy(size_t i, size_t n, char *dest, char *source)
{
	while (i < n)
	{
		dest[i] = source[i];
		i++;
	}
	return (dest);
}

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*dest;
	char	*source;

	dest = (char *) dst;
	source = (char *) src;
	if (dst == src)
		return (dst);
	if (src > dst)
	{
		i = 0;
		dest = ft_copy(i, n, dest, source);
	}
	else
	{
		i = n - 1;
		while ((int)i >= 0)
		{
			dest[i] = source[i];
			i--;
		}
	}
	return (dst);
}
