/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circ_stack_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirzall <ahirzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:56:38 by ahirzall          #+#    #+#             */
/*   Updated: 2025/02/19 19:50:23 by ahirzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circular_stack.h"
#include <stdlib.h>

void	rotate_circ_stack(t_stack *s)
{
	if (s && s->list.size > 1)
	{
		s->list.head = s->list.head->next;
		s->list.tail = s->list.tail->next;
	}
}
