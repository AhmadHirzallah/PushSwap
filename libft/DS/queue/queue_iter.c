/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_iter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirzall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 19:41:37 by ahirzall          #+#    #+#             */
/*   Updated: 2025/02/11 19:41:38 by ahirzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

short	queue_iter(t_queue *q, short (*f)(void *))
{
	t_dlist_node	*current;

	if (!q || !f)
		return (-1);
	current = q->list->head;
	while (current)
	{
		if (f(current->data) != 0)
			return (1);
		current = current->next;
	}
	return (0);
}
