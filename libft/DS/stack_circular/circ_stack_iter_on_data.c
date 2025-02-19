/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circ_stack_iter_on_data.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirzall <ahirzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:57:06 by ahirzall          #+#    #+#             */
/*   Updated: 2025/02/19 19:44:59 by ahirzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circular_stack.h"

short	stack_iter_on_data(t_stack *s, int (*f)(void *))
{
	t_list_node	*current;
	size_t		i;

	if (!s || !f)
	{
		return (-1);
	}
	current = s->list.head;
	i = 0;
	while (i < s->list.size)
	{
		if (f(current->data_s.data.as_ptr) != 0)
			return (1);
		current = current->next;
		i++;
	}
	return (0);
}
