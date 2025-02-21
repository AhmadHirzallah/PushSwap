/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils_two.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirzall <ahirzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 19:35:28 by ahirzall          #+#    #+#             */
/*   Updated: 2025/02/21 03:04:46 by ahirzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_headers.h"

int get_circular_len(t_list_node *head)
{
	t_list_node *curr;
	int len;

	if (!head)
		return (0);
	len = 0;
	curr = head;
	while (1)
	{
		len++;
		curr = curr->next;
		if (curr == head)
			break;
	}
	return (len);
}

////// Maybe needed function...
// void assign_index_flags(t_list_node *head, int middle)
// {
//     t_list_node *curr;
//     int index;

//     index = 0;
//     curr = head;
//     while (1)
//     {
//         curr->index = index;
//         if (index <= middle)
//             turk_set_flag(curr, BELOW_MEDIAN);
//         else
//             turk_set_flag(curr, ABOVE_MEDIAN);
//         index++;
//         curr = curr->next;
//         if (curr == head)
//             break;
//     }
// }

// void current_index(t_list_node *head)
// {
// 	int len;
// 	int middle;

// 	len = get_circular_len(head);
// 	if (len == 0)
// 		return;
// 	if (len % 2 == 0)
// 		middle = len / 2;
// 	else 
// 		middle = (len / 2) + 1;
	
// 	assign_index_flags(head, middle);
// }

t_list_node *find_closest_smaller(t_list_node *b_head, int a_nbr)
{
	t_list_node *curr;
	t_list_node *target;
	long best;

	if (!b_head)
		return (NULL);
	best = LONG_MIN;
	target = NULL;
	curr = b_head;
	while (1)
	{
		if ((get_node_value(curr) < a_nbr) &&
			(get_node_value(curr) > best))
		{
			best = get_node_value(curr);
			target = curr;
		}
		curr = curr->next;
		if (curr == b_head)
			break;
	}
	return (target);
}

/*
** set_target_a:
** Assigns the best target in B for each node in A.
*/
void set_target_a(t_list_node *a_head, t_list_node *b_head)
{
	t_list_node *curr;
	t_list_node *target;

	if (!a_head || !b_head)
		return;
	curr = a_head;
	while (1)
	{
		target = find_closest_smaller(b_head, get_node_value(curr));
		if (!target)
			target = find_max_node(b_head);
		curr->target = target;
		curr = curr->next;
		if (curr == a_head)
			break;
	}
}