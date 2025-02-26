/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils_three.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirzall <ahirzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 21:26:32 by ahirzall          #+#    #+#             */
/*   Updated: 2025/02/22 21:48:18 by ahirzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_headers.h"

t_list_node	*find_target_for_b(t_list_node *b_node, t_stack *a)
{
	int			b_val;
	long		best_match;
	t_list_node	*target;
	t_list_node	*current;

	b_val = get_ptr_int(b_node);
	best_match = LONG_MAX;
	target = NULL;
	current = a->list.head;
	while (1)
	{
		if (get_node_value(current) > b_val
			&& get_node_value(current) < best_match)
		{
			best_match = get_node_value(current);
			target = current;
		}
		current = current->next;
		if (current == a->list.head)
			break ;
	}
	if (target == NULL)
		target = find_min_node(a->list.head);
	return (target);
}

t_list_node	*find_min_node(t_list_node *head)
{
	t_list_node	*current;
	t_list_node	*min_node;
	int			min_val;
	int			current_val;

	if (!head)
		return (NULL);
	min_node = head;
	current = head->next;
	min_val = get_node_value(min_node);
	while (current != head)
	{
		current_val = get_node_value(current);
		if (current_val < min_val)
		{
			min_val = current_val;
			min_node = current;
		}
		current = current->next;
	}
	return (min_node);
}

static t_stacks_oprs	set_rotation_type_nbr(t_stacks_oprs dir,
		long *common_rot, long a_rot, long b_rot)
{
	if (a_rot < b_rot)
		*common_rot = a_rot;
	else
		*common_rot = b_rot;
	if (dir == ROTATION)
		dir = RR;
	else if (dir == REV_ROTATION)
		dir = RRR;
	return (dir);
}

static void	perform_combined_rotations(t_stacks *stacks,
		t_rotation_params *a_params, t_rotation_params *b_params)
{
	long			common_rot;
	t_stacks_oprs	new_ops;

	if (a_params->direction == b_params->direction)
	{
		new_ops = set_rotation_type_nbr(a_params->direction, &common_rot,
				a_params->rotations, b_params->rotations);
		while (common_rot > 0)
		{
			perform_ps_operations(new_ops, stacks);
			common_rot--;
			a_params->rotations--;
			b_params->rotations--;
		}
	}
}

// static void	perform_combined_rotations(t_stacks *stacks,
// 									long *a_rot, t_stacks_oprs *a_dir,
// 									long *b_rot, t_stacks_oprs *b_dir)
// {
// 	long common_rot;
// 	t_stacks_oprs new_ops;

// 	if (*a_dir == *b_dir)
// 	{
// 		new_ops = set_rotation_type_nbr(*a_dir, &common_rot, *a_rot, *b_rot);
// 		while (common_rot > 0)
// 		{
// 			perform_ps_operations(new_ops, stacks);
// 			common_rot--;
// 			(*a_rot)--;
// 			(*b_rot)--;
// 		}
// 	}
// }

void	perform_rotations(t_stacks *stacks, t_rotation_params *a_params,
		t_rotation_params *b_params)
{
	perform_combined_rotations(stacks, a_params, b_params);
	while (a_params->rotations > 0)
	{
		if (a_params->direction == ROTATION)
			perform_ps_operations(RA, stacks);
		else
			perform_ps_operations(RRA, stacks);
		a_params->rotations--;
	}
	while (b_params->rotations > 0)
	{
		if (b_params->direction == ROTATION)
			perform_ps_operations(RB, stacks);
		else
			perform_ps_operations(RRB, stacks);
		b_params->rotations--;
	}
}

// void	perform_rotations(t_stacks *stacks,
// 									long a_rot, t_stacks_oprs a_dir,
// 									long b_rot, t_stacks_oprs b_dir)
// {
// 	perform_combined_rotations(stacks, &a_rot, &a_dir, &b_rot, &b_dir);
// 	while (a_rot > 0)
// 	{
// 		if (a_dir == ROTATION)
// 			perform_ps_operations(RA, stacks);
// 		else
// 			perform_ps_operations(RRA, stacks);
// 		a_rot--;
// 	}
// 	while (b_rot > 0)
// 	{
// 		if (b_dir == ROTATION)
// 			perform_ps_operations(RB, stacks);
// 		else
// 			perform_ps_operations(RRB, stacks);
// 		b_rot--;
// 	}
// }
