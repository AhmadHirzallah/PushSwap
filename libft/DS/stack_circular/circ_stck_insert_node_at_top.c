/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circ_stck_insert_node_at_top.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirzall <ahirzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:57:25 by ahirzall          #+#    #+#             */
/*   Updated: 2025/02/19 15:57:26 by ahirzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circular_stack.h"

void	circ_stck_insert_node_at_top(t_stack *s, t_list_node *node)
{
	if (!s || !node)
		return ;
	if (s->list.size == 0)
	{
		node->next = node;
		node->prev = node;
		s->list.head = node;
		s->list.tail = node;
	}
	else
	{
		node->next = s->list.head;
		node->prev = s->list.tail;
		s->list.tail->next = node;
		s->list.head->prev = node;
		s->list.head = node;
	}
	s->list.size++;
}
