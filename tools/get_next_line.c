/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaciri- <hnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 19:32:41 by hnaciri-          #+#    #+#             */
/*   Updated: 2024/01/08 15:38:00 by hnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	*ft_memset(void *b, int c, size_t len) {
	char	*str;

	str = (char *)b;
	while (len)
	{
		*str = c;
		str++;
		len--;
	}
	return (b);
}

char	*get_line(char *line, int rd, char *readed, int fd)
{
	char	*tmp;

	while (!(ft_strchr(line, '\n')) && rd)
	{
		ft_memset(readed, 0, 2);
		rd = read (fd, readed, 1);
		if (rd == 0)
			return (line);
		if (rd < 0)
			fatal_error("Can not read the input");
		readed[rd] = 0;
		tmp = line;
		line = ft_strjoin (line, readed);
		free (tmp);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char	*line;
	int		rd;
	int		len;
	char	*readed;

	readed = malloc(sizeof(char) * 2);
	if (!readed)
		return (0);
	line = 0;
	rd = 1;
	line = get_line(line, rd, readed, fd);
	free (readed);
	if (line != NULL) {
		len = ft_strlen(line);
		if (len && line[len - 1] == '\n')
			line[len - 1] = 0;
	}
	return (line);
}