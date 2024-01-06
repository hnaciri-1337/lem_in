/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaciri- <hnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:48:10 by hnaciri-          #+#    #+#             */
/*   Updated: 2024/01/06 18:36:51 by hnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

void	allocator(char *fileName) {
	FILE	*file_in = fopen(fileName, "r");
	char    line[100];

	fscanf(file_in, "%d\n", &g_data.numberOfAnts);

	while (fgets(line, sizeof(line), file_in)) {
		char	roomName[100];
		char	lRoom[100];
		char	rRoom[100];
		int		x;
		int		y;

		if (line[0] == '#') {
			if (ft_strcmp(line, "##start\n") == 0) {
				fgets(line, sizeof(line), file_in);
				g_data.numberOfRooms++;
			}
			else  if (ft_strcmp(line, "##end\n") == 0) {
				fgets(line, sizeof(line), file_in);
				g_data.numberOfRooms++;
			}
		}
		else if (sscanf(line, "%s %d %d", roomName, &x, &y) == 3)
			g_data.numberOfRooms++;
		else if (sscanf(line, "%[^-]-%s", lRoom, rRoom) == 2)
			g_data.numberOfRelations++;
		else
			exit (printf ("Unknown string found: %s\n", line)) ;
	}
	fclose(file_in);
	g_data.graph = malloc(sizeof(t_room) * g_data.numberOfRooms);
	g_data.relations = malloc(sizeof(t_relation) * g_data.numberOfRelations + 1);
}

void	dataFill(char *fileName) {
	FILE	*file_in = fopen(fileName, "r");
	char    line[100];

	fscanf(file_in, "%d\n", &g_data.numberOfAnts);

	while (fgets(line, sizeof(line), file_in)) {
		char	roomName[100];
		char	lRoom[100];
		char	rRoom[100];
		int		x;
		int		y;

		if (line[0] == '#') {
			if (ft_strcmp(line, "##start\n") == 0) {
				fgets(line, sizeof(line), file_in);
				if (sscanf(line, "%s %d %d", roomName, &x, &y) != 3)
					exit (printf ("Unknown line found: %s\n", line));
				g_data.graph[g_data.numberOfRooms].name = ft_strdup(roomName);
				g_data.graph[g_data.numberOfRooms].x = x;
				g_data.graph[g_data.numberOfRooms].y = y;
				g_data.graph[g_data.numberOfRooms].numberOfNeighbors = 0;
				g_data.graph[g_data.numberOfRooms].neighbors = NULL;
				g_data.graph[g_data.numberOfRooms].parent = NULL;
				g_data.graph[g_data.numberOfRooms].visited = 0;
				g_data.graph[g_data.numberOfRooms].usedInPath = 0;
				g_data.start = &g_data.graph[g_data.numberOfRooms++]; 
			}
			else  if (ft_strcmp(line, "##end\n") == 0) {
				fgets(line, sizeof(line), file_in);
				if (sscanf(line, "%s %d %d", roomName, &x, &y) != 3)
					exit (printf ("Unknown line found: %s\n", line));
				g_data.graph[g_data.numberOfRooms].name = ft_strdup(roomName);
				g_data.graph[g_data.numberOfRooms].x = x;
				g_data.graph[g_data.numberOfRooms].y = y;
				g_data.graph[g_data.numberOfRooms].numberOfNeighbors = 0;
				g_data.graph[g_data.numberOfRooms].neighbors = NULL;
				g_data.graph[g_data.numberOfRooms].parent = NULL;
				g_data.graph[g_data.numberOfRooms].visited = 0;
				g_data.graph[g_data.numberOfRooms].usedInPath = 0;
				g_data.end = &g_data.graph[g_data.numberOfRooms++];
			}
		}
		else if (sscanf(line, "%s %d %d", roomName, &x, &y) == 3) {
			g_data.graph[g_data.numberOfRooms].name = ft_strdup(roomName);
			g_data.graph[g_data.numberOfRooms].x = x;
			g_data.graph[g_data.numberOfRooms].y = y;
			g_data.graph[g_data.numberOfRooms].numberOfNeighbors = 0;
			g_data.graph[g_data.numberOfRooms].neighbors = NULL;
			g_data.graph[g_data.numberOfRooms].parent = NULL;
			g_data.graph[g_data.numberOfRooms].usedInPath = 0;
			g_data.graph[g_data.numberOfRooms++].visited = 0;
		}
		else if (sscanf(line, "%[^-]-%s", lRoom, rRoom) == 2) {
			g_data.relations[g_data.numberOfRelations].lRoom = ft_strdup(lRoom);
			g_data.relations[g_data.numberOfRelations].rRoom = ft_strdup(rRoom);
			g_data.relations[g_data.numberOfRelations++].next = NULL;
		}
		else
			exit (printf ("Unknown line found: %s\n", line));
	}
	fclose(file_in);
}

t_room	*getRoomByName(char *name) {
	for (int i = 0; i < g_data.numberOfRooms; i++) {
		if (ft_strcmp(name, g_data.graph[i].name) == 0)
			return (&g_data.graph[i]);
	}
	return (NULL);
}

void	countRoomRelations(t_room *room) {
	for (int i = 0; i < g_data.numberOfRelations; i++) {
		room->numberOfNeighbors += (ft_strcmp(room->name, g_data.relations[i].lRoom) == 0);
		room->numberOfNeighbors += (ft_strcmp(room->name, g_data.relations[i].rRoom) == 0);
	}
}

void	createGraph() {
	t_room	*firstRoom;
	t_room	*secondRoom;

	for (int i = 0; i < g_data.numberOfRooms; i++) {
		countRoomRelations(&g_data.graph[i]);
		g_data.graph[i].neighbors = malloc (sizeof(t_room *) * g_data.graph[i].numberOfNeighbors);
		g_data.graph[i].numberOfNeighbors = 0;
	}
	for (int i = 0; i < g_data.numberOfRelations; i++) {
		if (!(firstRoom = getRoomByName(g_data.relations[i].lRoom)))
			exit (printf("fatal error\n"));
		if (!(secondRoom = getRoomByName(g_data.relations[i].rRoom)))
			exit (printf("fatal error\n"));
		firstRoom->neighbors[firstRoom->numberOfNeighbors++] = secondRoom;
		secondRoom->neighbors[secondRoom->numberOfNeighbors++] = firstRoom;
	}
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
	createGraph();
}
