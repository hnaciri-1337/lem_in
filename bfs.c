/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaciri- <hnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 19:37:20 by hnaciri-          #+#    #+#             */
/*   Updated: 2024/01/04 19:38:56 by hnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	bfs() {
    enqueue(g_data.queue, g_data.start);
	g_data.start->visited = 1;

	while (!queueIsEmpty(g_data.queue)) {
        t_room *currentRoom = dequeue(g_data.queue);
        if (currentRoom == g_data.end)
			printf ("Arrived first: %s\n", currentRoom->parent->name);
        for (int i = 0; i < currentRoom->numberOfNeighbors; i++) {
            t_room *neighbor = currentRoom->neighbors[i];
            if (neighbor->visited == 0) {
                neighbor->visited = 1;
                neighbor->parent = currentRoom;
                enqueue(g_data.queue, neighbor);
            }
        }
    }	
}
