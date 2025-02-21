/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms_turk.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirzall <ahirzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 20:42:37 by ahirzall          #+#    #+#             */
/*   Updated: 2025/02/21 02:31:30 by ahirzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_headers.h"

static t_list_node *select_candidate(t_stacks *stacks, long *min_cost)
{
    t_list_node *current;
    t_list_node *candidate;
    size_t i;

    candidate = NULL;
    *min_cost = LONG_MAX;
    current = stacks->a->list.head;
    i = -1;
    while (++i < stacks->a->list.size)
    {
        current->target = find_target_node(current, stacks->b);
        current->push_cost = compute_push_cost(current, current->target, stacks);
        if (current->push_cost < *min_cost)
        {
            *min_cost = current->push_cost;
            candidate = current;
            if (current->push_cost <= 1)
                return (current);
        }
        current = current->next; 
    }
    return (candidate);
}

static void process_candidate(t_stacks *stacks, t_list_node *candidate)
{
    t_stacks_oprs a_dir;
    t_stacks_oprs b_dir;
    long a_rot;
    long b_rot;

    calculate_rotations(stacks->a, candidate, &a_dir, &a_rot);
    rotate_stack(stacks->a, a_rot, a_dir, 'a');
    calculate_rotations(stacks->b, candidate->target, &b_dir, &b_rot);
    rotate_stack(stacks->b, b_rot, b_dir, 'b');
    pb(stacks->a, stacks->b);
}

void turk_algorithm(t_stacks *stacks)
{
    t_list_node *candidate;
    long min_cost;

    while (stacks->a->list.size > 5 && !is_stack_sorted(stacks->a))
    {
        refresh_stacks_all(stacks);
        candidate = select_candidate(stacks, &min_cost);
        if (candidate == NULL)
            break;
        process_candidate(stacks, candidate);
    }
    if (stacks->a->list.size <= 5)
        sort_five(stacks);
    while (stacks->b->list.size > 0)
        perform_ps_operations(PA, stacks);
}
