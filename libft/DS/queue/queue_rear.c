/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_rear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirzall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 19:41:41 by ahirzall          #+#    #+#             */
/*   Updated: 2025/02/11 19:41:41 by ahirzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

void	*queue_rear(const t_queue *q)
{
	const t_dlist_node	*rear;

	if (!q)
		return (NULL);
	rear = dlist_back(q->list);
	if (rear)
		return (rear->data);
	return (NULL);
}
/*
void	*queue_rear(const t_queue *q)
{
	const t_dlist_node	*rear;

	if (!q)
		return (NULL);
	rear = dlist_back(q->list);
	return (rear ? rear->data : NULL);
}
*/
