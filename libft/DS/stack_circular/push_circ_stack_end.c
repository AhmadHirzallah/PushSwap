/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_circ_stack_end.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirzall <ahirzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:57:37 by ahirzall          #+#    #+#             */
/*   Updated: 2025/02/19 19:47:58 by ahirzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circular_stack.h"
#include <stdlib.h>

short	push_circ_stack_end(t_stack *s, void *data)
{
	if (!s)
		return (-1);
	return (circ_list_insert_end(&s->list, data));
}
