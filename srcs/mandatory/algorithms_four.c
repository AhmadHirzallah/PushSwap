/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_four.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirzall <ahirzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 07:32:32 by ahirzall          #+#    #+#             */
/*   Updated: 2025/02/20 07:40:28 ahirzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_headers.h"

// static t_list_node *find_closest_smaller(t_list_node *b, int a_nbr)
// {
// 	t_list_node *current;
// 	t_list_node *target;
// 	long         best;

// 	best = LONG_MIN;
// 	current = b;
// 	target = NULL;
	
// 	while (current)
// 	{
// 		if ((get_node_value(current) < a_nbr) && (get_node_value(current) > best))
// 		{
// 			best = get_node_value(current);
// 			target = current;
// 		}
// 		current = current->next;
// 	}
// 	return (target);
// }

// void set_target_a(t_list_node *a, t_list_node *b)
// {
// 	t_list_node *target;

// 	while (a)
// 	{
// 		target = find_closest_smaller(b, get_node_value(a));
// 		if (!target)
// 			target = find_max(b);
// 		a->target = target;
// 		a = a->next;
// 	}
// }

t_list_node *find_target_node(t_list_node *a_node, t_stack *b)
{
	int			a_val;
	long			closest;
	size_t			count;
	t_list_node	*current;
	t_list_node	*target;

	if (b->list.size == 0)
		return (NULL);
	a_val = get_ptr_int(a_node);
	closest = LONG_MIN;
	target = NULL;
	count = -1;
	current = b->list.head;
	while (++count < b->list.size)
	{
		if ((get_ptr_int(current) < a_val) && (get_ptr_int(current) > closest))
		{
			closest = get_ptr_int(current);
			target = current;
		}
		current = current->next;
	}
	if (closest == LONG_MIN)
		return (find_max_node(b->list.head));
	return (target);
}
