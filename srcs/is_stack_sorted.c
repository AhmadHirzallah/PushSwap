/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_stack_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirzall <ahirzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 19:35:08 by ahirzall          #+#    #+#             */
/*   Updated: 2025/02/19 22:28:06 by ahirzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_headers.h"

int	get_node_value(t_list_node *node)
{
	return (*(int *)(node->data_s.data.as_ptr));
}

static short	check_asending_forwrd(t_list_node *head, size_t half)
{
	size_t	i;

	i = 0;
	while (i < half)
	{
		if (get_node_value(head) > get_node_value(head->next))
			return (0);
		head = head->next;
		i++;
	}
	return (1);
}

static short	check_descending_backwrd(t_list_node *tail, size_t half)
{
	size_t	i;

	i = 0;
	while (i < half)
	{
		if (get_node_value(tail->prev) > get_node_value(tail))
			return (0);
		tail = tail->prev;
		i++;
	}
	return (1);
}

int	is_stack_sorted(t_stack *stack)
{
	size_t	half;

	if (!stack || stack->list.size < 2)
		return (1);
	half = ((stack->list.size) / 2);
	if (!check_asending_forwrd(stack->list.head, half))
		return (0);
	if (!check_descending_backwrd(stack->list.tail, half))
		return (0);
	return (1);
}
