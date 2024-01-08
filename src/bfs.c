/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaciri- <hnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 19:37:20 by hnaciri-          #+#    #+#             */
/*   Updated: 2024/01/08 01:06:50 by hnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	initializePaths() {
	g_data.paths = malloc(sizeof(t_path) * g_data.start->numberOfNeighbors);
	g_data.numberOfAvailablePaths = 0;
}

void    getPath(t_room *room) {
	t_room	*tmp = room;
	int		i;
	
	g_data.paths[g_data.numberOfAvailablePaths].length = 0;
	while (tmp) {
		g_data.paths[g_data.numberOfAvailablePaths].length++;
		tmp = tmp->parent;
	}
	g_data.paths[g_data.numberOfAvailablePaths].path = malloc(sizeof(t_room *) * (g_data.paths[g_data.numberOfAvailablePaths].length + 1));
	i = g_data.paths[g_data.numberOfAvailablePaths].length;
	g_data.paths[g_data.numberOfAvailablePaths].path[--i] = g_data.end;
	tmp = room;
	while (tmp && tmp->parent) {
		tmp->usedInPath = 1;
		g_data.paths[g_data.numberOfAvailablePaths].path[--i] = tmp;
		tmp = tmp->parent;
	}
	g_data.paths[g_data.numberOfAvailablePaths].antsInPath = 0;
	g_data.paths[g_data.numberOfAvailablePaths].path[g_data.paths[g_data.numberOfAvailablePaths].length] = NULL;
	g_data.numberOfAvailablePaths++;
}

int	bfs() {
	g_data.queue = createQueue(g_data.numberOfRooms);
	enqueue(g_data.queue, g_data.start);
	g_data.start->visited = 1;

	while (!queueIsEmpty(g_data.queue)) {
		t_room *currentRoom = dequeue(g_data.queue);

		for (int i = 0; i < currentRoom->numberOfNeighbors; i++) {
			t_room *neighbor = currentRoom->neighbors[i];
			if (neighbor == g_data.end) {
				getPath(currentRoom);
				free (g_data.queue->queue);
				free (g_data.queue);
				return 1;
			}
			else if (neighbor->visited == 0) {
				neighbor->visited = 1;
				neighbor->parent = currentRoom;
				enqueue(g_data.queue, neighbor);
			}
		}
	}
	free (g_data.queue->queue);
	free (g_data.queue);
	return 0;
}
