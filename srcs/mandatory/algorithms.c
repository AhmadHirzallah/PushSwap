/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirzall <ahirzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 19:35:18 by ahirzall          #+#    #+#             */
/*   Updated: 2025/02/21 03:07:08 by ahirzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_headers.h"

int	get_ptr_int(t_list_node *node)
{
	if (!node)
		return (0);
	return (*(int *)node->data_s.data.as_ptr);
}

static void	rotate_min_data_upward(t_stack *a, long index)
{
	while (index > 0)
	{
		ra(a);
		index--;
	}
}

static void	rotate_min_data_downward(t_stack *a, long moves)
{
	while (moves > 0)
	{
		rra(a);
		moves--;
	}
}

void	push_min_into_b(t_stacks *stacks)
{
	long	index;
	long	half;
	long	moves;

	index = find_min_data_index(&stacks->a->list);
	half = (stacks->a->list.size) / 2;
	if (stacks->a->list.size % 2 == 1)
		half += 1;
	if (index <= half)
		rotate_min_data_upward(stacks->a, index);
	else
	{
		moves = stacks->a->list.size - index;
		rotate_min_data_downward(stacks->a, moves);
	}
	pb(stacks->a, stacks->b);
}

void	sort_five(t_stacks *stacks)
{
	t_stack	*a;

	if (!stacks || !stacks->a || stacks->a->list.size > 5)
		return ;
	a = stacks->a;
	while (a->list.size > 3)
	{
		refresh_stacks_all(stacks);
		push_min_into_b(stacks);
	}
	sort_three(stacks->a);
	while (stacks->b->list.size > 0)
	{
		refresh_stacks_all(stacks);
		perform_ps_operations(PA, stacks);
	}
	refresh_stacks_all(stacks);
}
