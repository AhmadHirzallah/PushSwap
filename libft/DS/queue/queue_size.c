/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirzall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 19:41:54 by ahirzall          #+#    #+#             */
/*   Updated: 2025/02/11 19:41:54 by ahirzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

size_t	queue_size(const t_queue *q)
{
	if (q)
		return (dlist_size(q->list));
	return (0);
}
/*
size_t	queue_size(const t_queue *q)
{
	return (q ? dlist_size(q->list) : 0);
}
*/
