/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirzall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 19:41:28 by ahirzall          #+#    #+#             */
/*   Updated: 2025/02/11 19:41:29 by ahirzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"
#include <stdlib.h>

void	queue_destroy(t_queue *q)
{
	if (!q)
		return ;
	dlist_clear(q->list);
	free(q->list);
	free(q);
}
