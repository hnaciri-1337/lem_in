/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaciri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 09:11:37 by hnaciri-          #+#    #+#             */
/*   Updated: 2021/11/09 14:28:19 by hnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	d;
	size_t	s;
	size_t	k;
	size_t	r;

	s = 0;
	while (src[s] != '\0')
		s++;
	d = 0;
	while (dest[d] != '\0')
		d++;
	if (size > d)
		r = s + d;
	else
		r = s + size;
	k = 0;
	while (src[k] != '\0' && (d + 1) < size)
	{
		dest[d] = src[k];
		d++;
		k++;
	}
	dest[d] = '\0';
	return (r);
}
