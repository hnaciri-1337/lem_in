/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaciri- <hnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:25:27 by hnaciri-          #+#    #+#             */
/*   Updated: 2024/01/04 19:37:02 by hnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	debug() {
	// printf ("Start :%s have %d neighbors\n", g_data.start->name, g_data.start->numberOfNeighbors);
	// for (int i = 0; i < g_data.start->numberOfNeighbors; i++)
	// 	printf ("%s: [%d , %d]\n", g_data.start->neighbors[i]->name, g_data.start->neighbors[i]->x, g_data.start->neighbors[i]->y);
	// printf ("\n\n");
	// printf ("End :%s have %d neighbors\n", g_data.end->name, g_data.start->numberOfNeighbors);
	// for (int i = 0; i < g_data.end->numberOfNeighbors; i++)
	// 	printf ("%s: [%d , %d]\n", g_data.end->neighbors[i]->name, g_data.end->neighbors[i]->x, g_data.end->neighbors[i]->y);
}

int main(int ac, char **av) {
	if (ac != 2)
		return (printf ("usage :\n./lem_in inputfile\n"));
	parser(av[1]);
	bfs();
}
