/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circ_stack_pop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirzall <ahirzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:56:57 by ahirzall          #+#    #+#             */
/*   Updated: 2025/02/19 19:46:47 by ahirzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circular_stack.h"
#include <stdlib.h>

void	*pop_circ_stack(t_stack *s)
{
	t_list_node	*node;
	void		*data;

	if (!s || is_circ_stack_empty(s))
	{
		return (NULL);
	}
	node = s->list.head;
	data = node->data_s.data.as_ptr;
	circ_list_remove_node(&s->list, node, NULL);
	return (data);
}
