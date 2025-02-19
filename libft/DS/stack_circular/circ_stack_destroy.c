/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circ_stack_destroy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirzall <ahirzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:57:09 by ahirzall          #+#    #+#             */
/*   Updated: 2025/02/19 19:36:28 by ahirzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circular_stack.h"
#include <stdlib.h>

void	destroy_circ_stack(t_stack *s)
{
	if (!s)
		return ;
	circ_list_clear(&s->list, s->del);
	free(s);
}
