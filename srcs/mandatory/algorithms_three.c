/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms_three.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirzall <ahirzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 04:11:31 by ahirzall          #+#    #+#             */
/*   Updated: 2025/02/21 02:32:29 by ahirzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_headers.h"

static long	compute_rotations(t_stack *s, t_list_node *n)
{
	int	rotations;
	int	size;
	int	index;

	size = s->list.size;
	index = n->index;
	if (index <= size / 2)
		rotations = index;
	else
		rotations = size - index;
	return (rotations);
}

void	calculate_rotations(t_stack *s, t_list_node *n, t_stacks_oprs *direction, long *rot_nbr)
{
	long	size;
	long	index;
	
	size = s->list.size;
	index = n->index;
	*rot_nbr = compute_rotations(s, n);
	if (index <= (size / 2))
		*direction = ROTATION;
	else
		*direction = REV_ROTATION;
}

// void	rotate_stack(t_stack *s, long rotations, t_stacks_oprs direction, char stack_name)
// {
// 	while (rotations > 0)
// 	{
// 		if (direction == ROTATION)
// 		{
// 			if (stack_name == 'a')
// 				ra(s);
// 			else if (stack_name == 'b')
// 				rb(s);
// 		}
// 		else if (direction == REV_ROTATION)
// 		{
// 			if (stack_name == 'a')
// 				rra(s);
// 			else if (stack_name == 'b')
// 				rrb(s);
// 		}
// 		rotations--;
// 	}
// }

long	compute_push_cost(t_list_node *a_node, t_list_node *b_target, t_stacks *s)
{
	t_stacks_oprs	a_dir;
	long			a_rot;
	t_stacks_oprs	b_dir;
	long			b_rot;

	calculate_rotations(s->a, a_node, &a_dir, &a_rot);
	calculate_rotations(s->b, b_target, &b_dir, &b_rot);
	if (a_dir == b_dir)
	{
		if (a_rot > b_rot)
			return (a_rot);
		else
			return (b_rot);
	}
	else
		return (a_rot + b_rot);
}

void	end_turk(t_stacks *s)
{
	t_list_node	*min_node;
	t_stacks_oprs ops;

	if (!s || !(s->a))
		return;
	refresh_stacks_all(s);
	min_node = find_min_node(s->a->list.head);
	if (s->a_middle >= min_node->index)
		ops = RA;
	else
		ops = RRA;
    while (s->a->list.head != min_node)
		perform_ps_operations(ops, s);
}