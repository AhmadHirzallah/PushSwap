/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirzall <ahirzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 19:35:22 by ahirzall          #+#    #+#             */
/*   Updated: 2025/02/21 03:20:58 by ahirzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_headers.h"

static void	refresh_stack_indices(t_stack *stack)
{
	t_list_node	*node;
	long		i;

	if(!stack || stack->list.size == 0)
		return ;
	node = stack->list.head;
	i = 0;
	while (1)
	{
		node->index = i++;
		node = node->next;
		if(node == stack->list.head)
			return ;
	}
}

static void	set_stacks_middles(t_stacks *stacks)
{
	if (stacks->a->list.size % 2)
		stacks->a_middle = (stacks->a->list.size) / 2;
	else
		stacks->a_middle = ((stacks->a->list.size) / 2) + 1;
	if (stacks->b->list.size % 2)
		stacks->b_middle = (stacks->b->list.size) / 2;
	else
		stacks->b_middle = ((stacks->b->list.size) / 2) + 1;
}

void	refresh_stacks_all(t_stacks *stacks)
{
	refresh_stack_indices(stacks->a);
	refresh_stack_indices(stacks->b);
	set_stacks_middles(stacks);
}


void	sorting_algorithms(t_sorting_cases sorting_type, t_stacks *stacks)
{
	if (sorting_type == SORT_TWO_NBRS)
		sort_two(stacks->a);
	else if (sorting_type == SORT_THREE_NBRS)
		sort_three(stacks->a);
	else if (sorting_type == SORT_FIVE_NBRS)
		sort_five(stacks);
	else
		turk_algorithm(stacks);
}


long find_min_data_index(t_circular_lst *list)
{
    t_list_node *current;
    long min_index;
    long min_value;

	min_value = LONG_MAX;
	min_index = 0;
    if (list->size == 0)
		return (-1);
    current = list->head;
    min_value = get_node_value(current);
    while (1)
    {
        if (get_node_value(current) < min_value)
		{
            min_value = get_node_value(current);
            min_index = current->index;
        }
        current = current->next;
		if (current == list->head)
			break;
    }

    return min_index;
}


