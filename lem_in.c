/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaciri- <hnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:25:27 by hnaciri-          #+#    #+#             */
/*   Updated: 2024/01/03 19:06:41 by hnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/libft.h"

t_relations	*relations = NULL;

int main() {
	int     numberOfAnts;
	char    line[100];

	scanf("%d\n", &numberOfAnts);
	while (fgets(line, sizeof(line), stdin)) {
		char	roomName[100];
		char	lRoom[100];
		char	rRoom[100];
		int		x;
		int		y;

		if (line[0] == '#') {
			if (ft_strncmp(line, "##start", 7) == 0) {
				fgets(line, sizeof(line), stdin);
			}
			else  if (ft_strncmp(line, "##end", 5) == 0) {
				fgets(line, sizeof(line), stdin);
			}
		}
		else if (sscanf(line, "%s %d %d", roomName, &x, &y) == 3) {
			
		}
		else if (sscanf(line, "%[^-]-%s", lRoom, rRoom) == 2) {
			ft_lstadd_front(&relations, ft_lstnew(lRoom, rRoom));
		}
		else
			exit (printf ("Unknown string found: %s\n", line)) ;
	}

	printf ("Relations :\n");
	
	while(relations) {
		printf ("%s <-----> %s\n", relations->lRoom, relations->rRoom);
		relations = relations->next;
	}
}
