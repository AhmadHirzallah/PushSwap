/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_queue_empty.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirzall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 19:41:15 by ahirzall          #+#    #+#             */
/*   Updated: 2025/02/11 19:41:16 by ahirzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

short	is_queue_empty(const t_queue *q)
{
	if (!q)
		return (1);
	if (is_dlist_empty(q->list))
		return (1);
	return (0);
}
/*
short	is_queue_empty(const t_queue *q)
{
	return (q ? dlist_empty(q->list) : 1);
}
*/
