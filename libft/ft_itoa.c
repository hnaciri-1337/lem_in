/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaciri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:18:24 by hnaciri-          #+#    #+#             */
/*   Updated: 2021/11/06 13:47:41 by hnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_alloc(long int nbr)
{
	int	counter;

	counter = 2;
	if (nbr < 10)
		return (counter);
	while (nbr >= 10)
	{
		nbr /= 10;
		counter++;
	}
	return (counter);
}

static char	*ft_negative(long int nbr)
{
	char		*str;
	int			i;
	long int	n;

	n = nbr;
	i = ft_alloc (nbr);
	str = malloc (sizeof(char) * (i + 1));
	if (str == 0)
		return (0);
	while (i--)
	{
		str[i] = (nbr % 10) + 48;
		nbr /= 10;
	}
	str[0] = '-';
	str[ft_alloc(n)] = 0;
	return (str);
}

char	*ft_itoa(int n)
{
	int			i;
	long int	nbr;
	char		*str;

	nbr = n;
	if (nbr < 0)
	{
		nbr *= -1;
		str = ft_negative(nbr);
	}
	else
	{
		i = ft_alloc (nbr) - 1;
		str = malloc (sizeof(char) * i + 1);
		if (str == 0)
			return (0);
		while (i--)
		{
			str[i] = (nbr % 10) + 48;
			nbr /= 10;
		}
		str[ft_alloc((long)n) - 1] = 0;
	}
	return (str);
}
