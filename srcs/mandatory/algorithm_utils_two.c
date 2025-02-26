/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils_two.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirzall <ahirzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 19:35:28 by ahirzall          #+#    #+#             */
/*   Updated: 2025/02/22 21:36:57 by ahirzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_headers.h"

int	get_circular_len(t_list_node *head)
{
	t_list_node	*curr;
	int			len;

	if (!head)
		return (0);
	len = 0;
	curr = head;
	while (1)
	{
		len++;
		curr = curr->next;
		if (curr == head)
			break ;
	}
	return (len);
}

t_list_node	*find_closest_smaller(t_list_node *b_head, int a_nbr)
{
	t_list_node	*curr;
	t_list_node	*target;
	long		best;

	if (!b_head)
		return (NULL);
	best = LONG_MIN;
	target = NULL;
	curr = b_head;
	while (1)
	{
		if ((get_node_value(curr) < a_nbr) && (get_node_value(curr) > best))
		{
			best = get_node_value(curr);
			target = curr;
		}
		curr = curr->next;
		if (curr == b_head)
			break ;
	}
	return (target);
}

void	set_target_a(t_list_node *a_head, t_list_node *b_head)
{
	t_list_node	*curr;
	t_list_node	*target;

	if (!a_head || !b_head)
		return ;
	curr = a_head;
	while (1)
	{
		target = find_closest_smaller(b_head, get_node_value(curr));
		if (!target)
			target = find_max_node(b_head);
		curr->target = target;
		curr = curr->next;
		if (curr == a_head)
			break ;
	}
}
