/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dequeue.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirzall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 19:41:10 by ahirzall          #+#    #+#             */
/*   Updated: 2025/02/11 19:41:11 by ahirzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

void	*dequeue(t_queue *q)
{
	void	*data;

	if (!q || is_queue_empty(q))
		return (NULL);
	data = queue_front(q);
	dlist_del_front(q->list);
	return (data);
}
