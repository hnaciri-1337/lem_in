/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaciri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 13:51:59 by hnaciri-          #+#    #+#             */
/*   Updated: 2021/11/10 15:05:01 by hnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	len;
	char			*str;
	unsigned int	i;

	if (!s || !f)
		return (0);
	i = 0;
	len = (unsigned int)ft_strlen((char *)s);
	str = malloc (sizeof(char) * (len + 1));
	if (str == 0)
		return (0);
	while (i < len)
	{
		str[i] = f (i, s[i]);
		i++;
	}
	str[i] = 0;
	return (str);
}
