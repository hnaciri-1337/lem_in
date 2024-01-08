/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaciri- <hnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 01:01:17 by hnaciri-          #+#    #+#             */
/*   Updated: 2024/01/08 15:48:39 by hnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

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
		if (!(firstRoom = getRoomByName(g_data.relations[i].lRoom))) {
			ft_putendl_fd("Error: Room name is relation but doesnt exist in Rooms", 2);
			fatal_error(g_data.relations[i].lRoom);
		}
		if (!(secondRoom = getRoomByName(g_data.relations[i].rRoom))) {
			ft_putendl_fd("Error: Room name is relation but doesnt exist in Rooms", 2);
			fatal_error(g_data.relations[i].rRoom);
		}
		firstRoom->neighbors[firstRoom->numberOfNeighbors++] = secondRoom;
		secondRoom->neighbors[secondRoom->numberOfNeighbors++] = firstRoom;
	}
}
