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
        if (currentRoom == g_data.end) {
			printf ("Arrived first: %s\n", currentRoom->parent->name);
            break ;
        }
        for (int i = 0; i < currentRoom->numberOfNeighbors; i++) {
            t_room *neighbor = currentRoom->neighbors[i];
            if (neighbor->visited == 0) {
                neighbor->visited = 1;
                neighbor->parent = currentRoom;
                enqueue(g_data.queue, neighbor);
            }
        }
    }
    if (g_data.end->parent == NULL) {
        printf("No path exists between start and end rooms.\n");
    } else {
        printf("Shortest path from start to end:\n");
        t_room *current = g_data.end;
        while (current != NULL) {
            printf("%s -> ", current->name);
            current = current->parent;
        }
        printf("NULL\n");
    }
}
