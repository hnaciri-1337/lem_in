/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaciri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 20:41:31 by hnaciri-          #+#    #+#             */
/*   Updated: 2021/11/10 13:06:27 by hnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_copy(char const *s1, char const *s2)
{
	char	*str;
	int		i;

	i = 0;
	if (s2 < s1)
	{
		str = malloc (1);
		str[0] = '\0';
		return (str);
	}
	str = malloc (sizeof(char) * ((s2 - s1) + 2));
	if (str == 0)
		return (0);
	while (s1 <= s2)
	{
		str[i] = *s1;
		s1++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char const	*s2;
	char		*str;

	if (!s1 || !set)
		return (0);
	if ((!*s1))
	{
		str = ft_calloc (1, sizeof(char));
		return (str);
	}
	while (ft_isset(set, *s1) && *s1 != '\0')
		s1++;
	s2 = s1;
	while (*s2 != '\0')
		s2++;
	s2--;
	while (ft_isset(set, *s2))
		s2--;
	str = ft_copy(s1, s2);
	return (str);
}
