/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirzall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 19:41:25 by ahirzall          #+#    #+#             */
/*   Updated: 2025/02/11 19:41:26 by ahirzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"
#include <stdlib.h>

t_queue	*queue_create(size_t max_size, void (*del)(void *))
{
	t_queue	*q;

	q = malloc(sizeof(t_queue));
	if (!q)
		return (NULL);
	q->list = malloc(sizeof(t_dlist));
	if (!q->list)
	{
		free(q);
		return (NULL);
	}
	dlist_init(q->list, del);
	q->max_size = max_size;
	return (q);
}
