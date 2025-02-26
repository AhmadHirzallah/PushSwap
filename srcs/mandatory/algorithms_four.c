/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms_four.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirzall <ahirzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 21:36:11 by ahirzall          #+#    #+#             */
/*   Updated: 2025/02/22 21:36:13 by ahirzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_headers.h"

t_list_node	*find_target_node(t_list_node *a_node, t_stack *b)
{
	int			a_val;
	long		closest;
	size_t		count;
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
