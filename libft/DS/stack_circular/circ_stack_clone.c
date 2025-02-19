/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circ_stack_clone.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirzall <ahirzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:57:14 by ahirzall          #+#    #+#             */
/*   Updated: 2025/02/19 19:50:12 by ahirzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circular_stack.h"
#include <stdlib.h>

t_stack	*circ_stack_clone(t_stack *s, void *(*copy)(void *),
		void (*del)(void *))
{
	t_stack		*clone;
	t_list_node	*current;
	void		*data_copy;
	size_t		i;

	if (!s || !copy)
		return (NULL);
	clone = create_circ_stack(del);
	if (!clone)
		return (NULL);
	current = s->list.head;
	i = -1;
	while (++i < s->list.size)
	{
		data_copy = copy(current->data_s.data.as_ptr);
		if (!data_copy || circ_list_insert_end(&clone->list, data_copy) != 0)
		{
			if (data_copy && del)
				del(data_copy);
			destroy_circ_stack(clone);
			return (NULL);
		}
		current = current->next;
	}
	return (clone);
}
