/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaciri- <hnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 13:42:03 by hnaciri-          #+#    #+#             */
/*   Updated: 2024/01/06 18:36:51 by hnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

void	printResult() {
	g_data.numberOfArrivedAnts = 0;
	g_data.numberOfRemainAnts = g_data.numberOfAnts;

	for (int i = 0; i < g_data.numberOfAvailablePaths; i++) 
		for (int j = 0; g_data.paths[i].path[j]; j++)
			g_data.paths[i].path[j]->antId = -1;
	
	int	sum = 0;
	for (int i = 0; i < g_data.numberOfAvailablePaths; i++) {
		if (i == 0 || (g_data.paths[i].length <= g_data.paths[i - 1].length + (g_data.numberOfRemainAnts - sum))) {
			g_data.numberOfRemainAnts--;
			g_data.paths[i].path[0]->antId = g_data.numberOfAnts - g_data.numberOfRemainAnts;
			printf ("L%d-%s ", g_data.paths[i].path[0]->antId, g_data.paths[i].path[0]->name);
		}
		else {
			g_data.numberOfAvailablePaths = i + 1;
			break ;
		}
		sum += g_data.paths[i].length;
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

		sum = 0;
		for (int i = 0; i < g_data.numberOfAvailablePaths && g_data.numberOfRemainAnts > 0; i++) {
			if (i == 0 || (g_data.paths[i].length <= (g_data.numberOfRemainAnts + sum))) {
				g_data.numberOfRemainAnts--;
				g_data.paths[i].path[0]->antId = g_data.numberOfAnts - g_data.numberOfRemainAnts;
				printf ("L%d-%s ", g_data.paths[i].path[0]->antId, g_data.paths[i].path[0]->name);
			}
			else
				break ;
			sum += g_data.paths[i].length;
		}
		printf ("\n");
	}
}
