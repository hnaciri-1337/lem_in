/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaciri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:09:55 by hnaciri-          #+#    #+#             */
/*   Updated: 2021/11/10 12:51:52 by hnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_alloc(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;

	i = 0;
	while (s[start + i] != '\0' && (size_t)i < len)
		i++;
	i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*str;

	if (!s)
		return (0);
	i = 0;
	if ((size_t)start >= ft_strlen(s))
	{
		str = malloc (1 * sizeof(char));
		if (str == NULL)
			return (NULL);
	}
	else
	{
		str = malloc ((ft_alloc(s, start, len)) * sizeof(char));
		if (str == NULL)
			return (NULL);
		while (s[start + i] != '\0' && (size_t)i < len)
		{
			str[i] = s[start + i];
			i++;
		}
	}
	str[i] = '\0';
	return (str);
}
