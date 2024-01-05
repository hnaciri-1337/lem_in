/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaciri- <hnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 19:37:20 by hnaciri-          #+#    #+#             */
/*   Updated: 2024/01/05 18:30:11 by hnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void    initializePaths() {
	g_data.paths = malloc(sizeof(t_path) * g_data.start->numberOfNeighbors);
	g_data.numberOfAvailablePaths = 0;
}

void    getPath(t_room *room) {
	t_room	*tmp = room;
	int		i;
	
	g_data.paths[g_data.numberOfAvailablePaths].length = 0;
	while (tmp) {
		if (tmp->usedInPath == 1)
			return ;
		g_data.paths[g_data.numberOfAvailablePaths].length++;
		tmp = tmp->parent;
	}
	tmp = room;
	i = g_data.paths[g_data.numberOfAvailablePaths].length;
	g_data.paths[g_data.numberOfAvailablePaths].path = malloc(sizeof(t_room *) * (g_data.paths[g_data.numberOfAvailablePaths].length + 1));
	while (tmp) {
		if (tmp != g_data.start)
			tmp->usedInPath = 1;
		g_data.paths[g_data.numberOfAvailablePaths].path[--i] = tmp;
		tmp = tmp->parent;
	}
	g_data.paths[g_data.numberOfAvailablePaths].path[g_data.paths[g_data.numberOfAvailablePaths].length] = NULL;
	g_data.numberOfAvailablePaths++;
}

void	bfs() {
	initializePaths();
	enqueue(g_data.queue, g_data.start);
	g_data.start->visited = 1;

	while (!queueIsEmpty(g_data.queue)) {
		t_room *currentRoom = dequeue(g_data.queue);

		for (int i = 0; i < currentRoom->numberOfNeighbors; i++) {
			t_room *neighbor = currentRoom->neighbors[i];
			if (neighbor == g_data.end) {
				// printf ("Arrived: %s\n", currentRoom->name);
				getPath(currentRoom);
			}
			else if (neighbor->visited == 0) {
				neighbor->visited = 1;
				neighbor->parent = currentRoom;
				enqueue(g_data.queue, neighbor);
			}
		}
	}
}
