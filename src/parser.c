/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaciri- <hnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:48:10 by hnaciri-          #+#    #+#             */
/*   Updated: 2024/01/08 15:51:55 by hnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	readNumberOfAnts(char *line) {
	g_data.numberOfAnts = ft_atoi(line);
}

void	readRoom(char *line) {
	char	*tmp;

	while (line && ft_isspace(*line))
		line++;
	tmp = line;
	while (*line && !ft_isspace(*line))
		line++;
	g_data.graph[g_data.numberOfRooms].name = ft_substr(tmp, 0, line - tmp);
	while (ft_isspace(*line))
		line++;
	g_data.graph[g_data.numberOfRooms].x = ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	while (ft_isspace(*line))
		line++;
	g_data.graph[g_data.numberOfRooms].y = ft_atoi(line);

	g_data.graph[g_data.numberOfRooms].numberOfNeighbors = 0;
	g_data.graph[g_data.numberOfRooms].neighbors = NULL;
	g_data.graph[g_data.numberOfRooms].parent = NULL;
	g_data.graph[g_data.numberOfRooms].visited = 0;
	g_data.graph[g_data.numberOfRooms].usedInPath = 0;
	g_data.numberOfRooms++;
}

void	readRelation(char *line) {
	char	**rooms = ft_split(line, '-');

	g_data.relations[g_data.numberOfRelations].lRoom = rooms[0];
	g_data.relations[g_data.numberOfRelations].rRoom = rooms[1];
	g_data.numberOfRelations++;

	free (rooms);
}

int		checkIfNumber(char *line) {
	while (line && ft_isspace(*line))
		line++;
	if (!line || !(*line))
		return 0;

	while (*line && ft_isdigit(*line))
		line++;
	return (!(*line));
}

int		checkIfRoom(char *line) {
	while (line && ft_isspace(*line))
		line++;
	if (!line || !(*line))
		return 0;

	while (*line && !ft_isspace(*line))
		line++;
	if (!(*line))
		return 0;
	
	if (ft_isspace(*line))
		while (ft_isspace(*line))
			line++;
	else
		return 0;
	if (!(*line))
		return 0;

	if (ft_isdigit(*line))
		while (ft_isdigit(*line))
			line++;
	else
		return 0;
	if (!(*line))
		return 0;

	if (ft_isspace(*line))
		while (ft_isspace(*line))
			line++;
	else
		return 0;
	if (!(*line))
		return 0;

	if (ft_isdigit(*line))
		while (ft_isdigit(*line))
			line++;
	else
		return 0;

	return (!(*line));
}

int		checkIfRelation(char *line) {
	int	count = 0;
	int	position = -1;
	int	i = 0;

	for (i = 0; line && line[i]; i++) {
		if (line[i] == '-') {
			count++;
			position = i;
		}
		if (!ft_isalnum(line[i]) && line[i] != '_' && line[i] != '-')
			return 0;
	}
	return (count == 1 && position != 0 && position != i - 1);
}

void	allocator(char *fileName) {
	int		fd = open(fileName, O_RDONLY);
	char    *line;

	line = get_next_line(fd);
	if (!checkIfNumber(line))
		fatal_error("Number of ants should be at the first line !");
	readNumberOfAnts(line);
	free(line);
	while ((line = get_next_line(fd))) {
		if (line[0] == '#') {
			if (ft_strcmp(line, "##start") == 0 || ft_strcmp(line, "##end") == 0) {
				free (line);
				line = get_next_line(fd);
				if (!checkIfRoom(line))
					fatal_error("Unknown line found !");
				g_data.numberOfRooms++;
			}
		}
		else if (checkIfRoom(line))
			g_data.numberOfRooms++;
		else if (checkIfRelation(line))
			g_data.numberOfRelations++;
		else
			fatal_error("Unknown line found !");
		free (line);
	}
	close(fd);
	g_data.graph = malloc(sizeof(t_room) * g_data.numberOfRooms);
	g_data.relations = malloc(sizeof(t_relation) * g_data.numberOfRelations + 1);
}

void	dataFill(char *fileName) {
	int		fd = open(fileName, 0);
	char    *line;

	line = get_next_line(fd);
	if (!checkIfNumber(line))
		fatal_error("Number of ants should be at the first line !");
	readNumberOfAnts(line);
	free(line);
	while ((line = get_next_line(fd))) {
		if (line[0] == '#') {
			if (ft_strcmp(line, "##start") == 0) {
				free (line);
				line = get_next_line(fd);
				readRoom(line);
				g_data.start = &g_data.graph[g_data.numberOfRooms - 1];
			}
			else  if (ft_strcmp(line, "##end") == 0) {
				free (line);
				line = get_next_line(fd);
				readRoom(line);
				g_data.end = &g_data.graph[g_data.numberOfRooms - 1];
			}
		}
		else if (checkIfRoom(line))
			readRoom(line);
		else if (checkIfRelation(line))
			readRelation(line);
		else
			fatal_error("Unknown line found !");
		free (line);
	}
	close(fd);
}

void	parser(char *fileName) {
	g_data.numberOfAnts = 0;
	g_data.numberOfRooms = 0;
	g_data.numberOfRelations = 0;
	g_data.graph = NULL;
	g_data.start = NULL;
	g_data.end = NULL;
	g_data.relations = NULL;
	allocator(fileName);
	g_data.numberOfAnts = 0;
	g_data.numberOfRooms = 0;
	g_data.numberOfRelations = 0;
	dataFill(fileName);
	if (!g_data.numberOfRooms || !g_data.numberOfRelations || !g_data.start || !g_data.end)
		fatal_error("File should containe all the required parametres\nNumber of ants\nrooms\nrelations");
}
