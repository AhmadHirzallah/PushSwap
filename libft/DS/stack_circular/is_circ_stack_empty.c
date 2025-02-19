/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_circ_stack_empty.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirzall <ahirzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:57:34 by ahirzall          #+#    #+#             */
/*   Updated: 2025/02/19 19:37:36 by ahirzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circular_stack.h"
#include <stdlib.h>

short	is_circ_stack_empty(const t_stack *s)
{
	if (s->list.size == 0)
		return (1);
	return (0);
}

/*
short	is_circ_stack_empty(const t_stack *s)
{
	return (s ? (s->size == 0) : 1);
}

*/