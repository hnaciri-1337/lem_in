/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaciri- <hnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 13:07:03 by hnaciri-          #+#    #+#             */
/*   Updated: 2024/01/08 01:06:59 by hnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int	ft_alloc(char const *str, char c)
{
	int	counter;
	int	i;

	i = 0;
	counter = 0;
	while (str[i] != '\0')
	{
		if (i == 0 || (str[i] != c && (str[i - 1] == c)))
			counter++;
		i++;
	}
	counter++;
	return (counter);
}

static int	ft_position(char const *s, int *position, char c)
{
	int	counter;

	counter = 0;
	while (s[(*position)] == c)
		(*position)++;
	while (s[(*position)] != c && s[(*position)] != '\0')
	{
		counter++;
		(*position)++;
	}
	counter++;
	return (counter);
}

static void	ft_address(char *dest, char const *src, char c, int i)
{
	int	j;

	j = 0;
	while (src[i] != '\0' && src[i] == c)
		i++;
	while (src[i] != '\0' && src[i] != c)
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
}

static char	**ft_fill(char const *s, char c, int *position, char **table)
{
	int	i;
	int	p;

	i = 0;
	while (i < (ft_alloc(s, c) - 1))
	{
		p = *position;
		table[i] = malloc (sizeof(char) * ft_position(s, position, c));
		if (table[i] == 0)
		{
			while (i--)
				free(table[i]);
			free (position);
			return (0);
		}
		ft_address(table[i], s, c, p);
		i++;
	}
	table[ft_alloc(s, c) - 1] = 0;
	free (position);
	return (table);
}

char	**ft_split(char const *s, char c)
{
	int		*position;
	char	**table;

	if (!s)
		return (0);
	position = malloc (1 * sizeof(int));
	if (!position)
		return (0);
	*position = 0;
	table = malloc (sizeof(char *) * ft_alloc(s, c));
	if (!table)
		return (0);
	table = ft_fill(s, c, position, table);
	if (!table)
	{
		free(table);
		return (0);
	}
	return (table);
}
