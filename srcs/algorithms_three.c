/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms_three.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirzall <ahirzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 04:11:31 by ahirzall          #+#    #+#             */
/*   Updated: 2025/02/20 07:32:26 by ahirzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_headers.h"

t_list_node *find_target_node(t_list_node *a_node, t_stack *b)
{
	int			a_val;
	int			closest;
	int			count;
	t_list_node	*current;
	t_list_node	*target;

	if (b->list.size = 0)
		return (NULL);
	a_val = get_ptr_int(a_node);
	closest = LONG_MIN;
	target = NULL;
	count = -1;
	current = b->list.head;
	while (++count < b->list.size)
	{
		if ((get_ptr_int(current) < a_val) && (get_ptr_int(current) > closest))
		{
			closest = get_ptr_int(current);
			target = current;
		}
		current = current->next;
	}
	if (closest == LONG_MIN)
		return (find_max_node(b));
	return (target);
}


static void	calculate_rotations(t_stack *s, t_list_node *n, t_stacks_oprs *direction, long *rot_nbr)
{
	long	size;
	long	index;
	
	size = s->list.size;
	index = n->index;
	if (index <= (size / 2))
	{
		*rot_nbr = index;
		direction = ROTATION;
	}
	else
	{
		*rot_nbr = size - index;
		direction = REV_ROTATION;
	}
}

long	compute_push_cost(t_list_node *a_node, t_list_node *b_target, t_stacks *s)
{
	t_stacks_oprs	a_dir;
	long	a_rot;
	t_stacks_oprs	b_dir;
	long	b_rot;
	
	calculate_rotations(s->a, a_node, &a_dir, &a_rot);
	calculate_rotations(s->b, b_target, &b_dir, &b_rot);
	if (a_dir == b_dir)
		if (a_rot > b_rot)
			return (a_rot);
		else
			return (a_rot + b_rot);
}
