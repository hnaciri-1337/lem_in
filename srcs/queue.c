/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaciri- <hnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:32:29 by hnaciri-          #+#    #+#             */
/*   Updated: 2024/01/09 18:32:30 by hnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_queue	*createQueue(int size) {
	t_queue   *q = malloc(sizeof(t_queue));

	q->queue = malloc(sizeof(t_room) * size);
	q->l = 0;
	q->r = -1;
	q->size = size;
	return (q);
}

int	queueIsFull(t_queue *q) {
	return (q->r == q->size - 1);
}

int	queueIsEmpty(t_queue *q) {
	return (q->l > q->r);
}

void	enqueue(t_queue	*q, t_room* room) {
	if (queueIsFull(q))
		return;
	q->queue[++q->r] = room;
}

t_room	*dequeue(t_queue* q) {
	if (queueIsEmpty(q))
		return NULL;
	return q->queue[q->l++];
}
