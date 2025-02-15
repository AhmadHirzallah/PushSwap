/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirzall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 19:57:24 by ahirzall          #+#    #+#             */
/*   Updated: 2025/02/11 19:57:28 by ahirzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H
# define QUEUE_H

# include "dlist.h"

typedef struct s_queue
{
	t_dlist	*list;
	size_t	max_size;
}			t_queue;

t_queue		*queue_create(size_t max_size, void (*del)(void *));
void		queue_destroy(t_queue *q);
short		enqueue(t_queue *q, void *data);
void		*dequeue(t_queue *q);
void		*queue_front(const t_queue *q);
void		*queue_rear(const t_queue *q);
size_t		queue_size(const t_queue *q);
short		is_queue_full(const t_queue *q);
short		is_queue_empty(const t_queue *q);
void		queue_clear(t_queue *q);
short		queue_iter(t_queue *q, short (*f)(void *));
t_queue		*queue_split(t_queue *q, size_t pos);

#endif
