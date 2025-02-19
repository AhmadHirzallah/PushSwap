/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circ_stck_remove_top_node.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirzall <ahirzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:57:32 by ahirzall          #+#    #+#             */
/*   Updated: 2025/02/19 15:57:33 by ahirzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circular_stack.h"

t_list_node	*circ_stck_remove_top_node(t_stack *s)
{
	t_list_node	*node;

	if (!s || s->list.size == 0)
		return (NULL);
	node = s->list.head;
	if (s->list.size == 1)
	{
		s->list.head = NULL;
		s->list.tail = NULL;
	}
	else
	{
		s->list.head = node->next;
		s->list.tail->next = s->list.head;
		s->list.head->prev = s->list.tail;
	}
	s->list.size--;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}
