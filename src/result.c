/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaciri- <hnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 13:42:03 by hnaciri-          #+#    #+#             */
/*   Updated: 2024/01/06 20:06:28 by hnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

void	assignAntsToPath() {

	for (int i = 0; i < g_data.numberOfAnts; i++) {
		t_path	*min = &g_data.paths[0];
		for (int j = 0; j < g_data.numberOfAvailablePaths; j++) {
			if ((g_data.paths[j].length + g_data.paths[j].antsInPath) < (min->length + min->antsInPath))
				min = &g_data.paths[j];
		}
		min->antsInPath++;
	}
}

void	printResult() {
	g_data.numberOfArrivedAnts = 0;
	g_data.numberOfRemainAnts = g_data.numberOfAnts;
	for (int i = 0; i < g_data.numberOfAvailablePaths; i++) 
		for (int j = 0; g_data.paths[i].path[j]; j++)
			g_data.paths[i].path[j]->antId = -1;

	assignAntsToPath();
	// return ;	
	g_data.numberOfRemainAnts = g_data.numberOfAnts;
	for (int i = 0; i < g_data.numberOfAvailablePaths; i++) {
		if (g_data.paths[i].antsInPath) {
			g_data.paths[i].antsInPath--;
			g_data.numberOfRemainAnts--;
			g_data.paths[i].path[0]->antId = g_data.numberOfAnts - g_data.numberOfRemainAnts;
			printf ("L%d-%s ", g_data.paths[i].path[0]->antId, g_data.paths[i].path[0]->name);
		}
		else {
			g_data.numberOfAvailablePaths = i + 1;
			break ;
		}
	}
	
	printf ("\n");

	while (g_data.numberOfArrivedAnts < g_data.numberOfAnts) {
		for (int i = 0; i < g_data.numberOfAvailablePaths; i++) {
			for (int j = g_data.paths[i].length - 1; j > 0; j--) {
				if (g_data.paths[i].path[j - 1]->antId != -1) {
					g_data.paths[i].path[j]->antId = g_data.paths[i].path[j - 1]->antId;
					g_data.paths[i].path[j - 1]->antId = -1;
					printf ("L%d-%s ", g_data.paths[i].path[j]->antId, g_data.paths[i].path[j]->name);
					if (g_data.paths[i].path[j] == g_data.end)
						g_data.numberOfArrivedAnts++;
				}
			}
		}

		for (int i = 0; i < g_data.numberOfAvailablePaths; i++) {
			if (g_data.paths[i].antsInPath) {
				g_data.paths[i].antsInPath--;
				g_data.numberOfRemainAnts--;
				g_data.paths[i].path[0]->antId = g_data.numberOfAnts - g_data.numberOfRemainAnts;
				printf ("L%d-%s ", g_data.paths[i].path[0]->antId, g_data.paths[i].path[0]->name);
			}
			else
				break ;
		}
		printf ("\n");
	}
}
