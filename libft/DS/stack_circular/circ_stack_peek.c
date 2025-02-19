/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circ_stack_peek.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirzall <ahirzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:57:02 by ahirzall          #+#    #+#             */
/*   Updated: 2025/02/19 19:36:42 by ahirzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circular_stack.h"
#include <stdlib.h>

void	*peek_circ_stack(const t_stack *s)
{
	if (!s || s->list.size == 0)
		return (NULL);
	return (s->list.head->data_s.data.as_ptr);
}
