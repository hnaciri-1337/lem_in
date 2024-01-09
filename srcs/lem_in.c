/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaciri- <hnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:25:27 by hnaciri-          #+#    #+#             */
/*   Updated: 2024/01/09 18:32:39 by hnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_global	g_data;

int main(int ac, char **av) {
	if (ac != 2)
		fatal_error("This is how to use !\n./lem_in inputfile");
	parser(av[1]);
	createGraph();
	initializePaths();
	while (bfs()) {
		for (int i = 0; i < g_data.numberOfRooms; i++)
			g_data.graph[i].visited = g_data.graph[i].usedInPath;
	}
	printResult();
}
