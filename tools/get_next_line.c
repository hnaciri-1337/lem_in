/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaciri- <hnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 19:32:41 by hnaciri-          #+#    #+#             */
/*   Updated: 2024/01/08 01:06:59 by hnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

char	*get_line(char *line, int rd, char *readed, int fd)
{
	char	*tmp;

	while (!(ft_strchr(line, '\n')) && rd)
	{
		rd = read (fd, readed, 1);
		if (rd == 0 && *readed == 0)
			return (0);
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
	if (line) {
		len = ft_strlen(line);
		if (line[len - 1] == '\n')
			line[len - 1] = 0;
	}
	return (line);
}