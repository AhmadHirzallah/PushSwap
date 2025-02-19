/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_circ_stack.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirzall <ahirzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:57:41 by ahirzall          #+#    #+#             */
/*   Updated: 2025/02/19 19:47:48 by ahirzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circular_stack.h"
#include <stdlib.h>

void	rev_rotate_circ_stack(t_stack *s)
{
	if (s && s->list.size > 1)
	{
		s->list.head = s->list.head->prev;
		s->list.tail = s->list.tail->prev;
	}
}
