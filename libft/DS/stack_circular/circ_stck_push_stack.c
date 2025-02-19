/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circ_stck_push_stack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirzall <ahirzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:57:29 by ahirzall          #+#    #+#             */
/*   Updated: 2025/02/19 19:47:21 by ahirzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circular_stack.h"

void	circ_stck_push_stack(t_stack *dest, t_stack *src)
{
	t_list_node	*node;

	node = circ_stck_remove_top_node(src);
	if (node)
		circ_stck_insert_node_at_top(dest, node);
}
