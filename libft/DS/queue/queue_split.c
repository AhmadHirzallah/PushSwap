/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirzall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 19:41:45 by ahirzall          #+#    #+#             */
/*   Updated: 2025/02/11 19:49:50 by ahirzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

t_queue	*queue_split(t_queue *q, size_t pos)
{
	t_queue			*new_q;
	t_dlist_node	*current;
	static size_t	count;

	if (!q || pos >= queue_size(q))
		return (NULL);
	new_q = queue_create(q->max_size, q->list->del);
	if (!new_q)
		return (NULL);
	current = q->list->head;
	while (count++ < pos)
		current = current->next;
	new_q->list->head = current;
	new_q->list->tail = q->list->tail;
	q->list->tail = current->prev;
	if (current->prev)
		current->prev->next = NULL;
	else
		q->list->head = NULL;
	current->prev = NULL;
	new_q->list->size = queue_size(q) - pos;
	q->list->size = pos;
	return (new_q);
}
