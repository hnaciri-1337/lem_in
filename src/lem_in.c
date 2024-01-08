/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaciri- <hnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:25:27 by hnaciri-          #+#    #+#             */
/*   Updated: 2024/01/08 01:06:50 by hnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_global	g_data;

void	debug() {
	// for (int i = 0; i < g_data.numberOfAvailablePaths; i++) {
	// 	printf ("Length: %d | Assigned: %d | Sum: %d\n", g_data.paths[i].length, g_data.paths[i].antsInPath, g_data.paths[i].length + g_data.paths[i].antsInPath);
	// 	for (int j = 0; g_data.paths[i].path[j]; j++)
	// 		printf ("%s -> ", g_data.paths[i].path[j]->name);
	// 	printf ("\n");
	// }
}

int main(int ac, char **av) {
	if (ac != 2)
		fatal_error("This is how to use !\n./lem_in inputfile");
	parser(av[1]);
	initializePaths();
	while (bfs()) {
		for (int i = 0; i < g_data.numberOfRooms; i++)
			g_data.graph[i].visited = g_data.graph[i].usedInPath;
	}
	printResult();
}
