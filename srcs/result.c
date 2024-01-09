/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaciri- <hnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 13:42:03 by hnaciri-          #+#    #+#             */
/*   Updated: 2024/01/09 18:33:27 by hnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

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

	while (g_data.numberOfArrivedAnts < g_data.numberOfAnts) {
		for (int i = 0; i < g_data.numberOfAvailablePaths; i++) {
			for (int j = g_data.paths[i].length - 1; j > 0; j--) {
				if (g_data.paths[i].path[j - 1]->antId != -1) {
					g_data.paths[i].path[j]->antId = g_data.paths[i].path[j - 1]->antId;
					g_data.paths[i].path[j - 1]->antId = -1;
					if (g_data.paths[i].path[j] == g_data.end)
						g_data.numberOfArrivedAnts++;
					ft_putchar_fd('L', 1);
					ft_putnbr_fd(g_data.paths[i].path[j]->antId, 1);
					ft_putchar_fd('-', 1);
					ft_putstr_fd(g_data.paths[i].path[j]->name, 1);
					ft_putchar_fd(' ', 1);
				}
			}
		}

		for (int i = 0; i < g_data.numberOfAvailablePaths; i++) {
			if (g_data.paths[i].antsInPath) {
				g_data.paths[i].antsInPath--;
				g_data.numberOfRemainAnts--;
				g_data.paths[i].path[0]->antId = g_data.numberOfAnts - g_data.numberOfRemainAnts;
				ft_putchar_fd('L', 1);
				ft_putnbr_fd(g_data.paths[i].path[0]->antId, 1);
				ft_putchar_fd('-', 1);
				ft_putstr_fd(g_data.paths[i].path[0]->name, 1);
				ft_putchar_fd(' ', 1);
			}
			else
				break ;
		}
		ft_putchar_fd ('\n', 1);
	}
}
