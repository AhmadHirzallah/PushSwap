/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enqueue.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirzall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 19:41:12 by ahirzall          #+#    #+#             */
/*   Updated: 2025/02/11 19:41:13 by ahirzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

short	enqueue(t_queue *q, void *data)
{
	if (!q || is_queue_full(q))
		return (-1);
	return (dlist_insert_end(q->list, data));
}
