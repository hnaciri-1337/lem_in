#include "libft/libft.h"

t_queue	*createQueue(int size) {
	t_queue   *q = (t_queue*)malloc(sizeof(t_queue));
	q->l = 0;
	q->r = -1;
	q->size = size;
	return q;
}

int	queueIsFull(t_queue *q) {
	return (q->r == q->size - 1);
}

int	queueIsEmpty(t_queue *q) {
	return (q->l > q->r);
}

void	enqueue(t_queue	*q, t_room* room) {
	if (isFull(q))
		return;
	q->queue[++q->r] = room;
}

t_room	*dequeue(t_queue* q) {
	if (queueIsEmpty(q))
		return NULL;
	return q->queue[q->l++];
}
