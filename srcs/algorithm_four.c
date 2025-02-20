/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_four.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirzall <ahirzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 07:32:32 by ahirzall          #+#    #+#             */
/*   Updated: 2025/02/20 07:40:28 ahirzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_headers.h"

void current_index(t_list_node *head)
{
	int i;
	int len;
	int median;
	t_list_node *curr;

	i = 0;
	len = circ_list_size(head);
	median = len / 2;
	curr = head;
	while (i < len)
	{
		set_index_and_median(curr, i, median);
		curr = curr->next;
		i++;
	}
}

static t_list_node *find_closest_smaller(t_list_node *b, int a_nbr)
{
	t_list_node *current;
	t_list_node *target;
	long         best;

	best = LONG_MIN;
	current = b;
	target = NULL;
	
	while (current)
	{
		if ((get_node_value(current) < a_nbr) && (get_node_value(current) > best))
		{
			best = get_node_value(current);
			target = current;
		}
		current = current->next;
	}
	return (target);
}

void set_target_a(t_list_node *a, t_list_node *b)
{
	t_list_node *target;

	while (a)
	{
		target = find_closest_smaller(b, get_node_value(a));
		if (!target)
			target = find_max(b);
		a->target = target;
		a = a->next;
	}
}