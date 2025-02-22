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


void b_stck_psh2_set_up(t_stacks *stacks)
{
    while (stacks->b->list.size < 2)
    {
        push_min_into_b(stacks);
        refresh_stacks_all(stacks);
    }
}

static t_list_node *select_candidate(t_stacks *stacks, long *min_cost)
{
    t_list_node *current;
    t_list_node *candidate;
    ssize_t i;

    candidate = NULL;
    *min_cost = LONG_MAX;
    current = stacks->a->list.head;
    i = -1;
    while (++i < (ssize_t)stacks->a->list.size)
    {
        current->target = find_target_node(current, stacks->b);
        current->push_cost = compute_push_cost(current, current->target, stacks);
        if (current->push_cost < *min_cost)
        {
            *min_cost = current->push_cost;
            candidate = current;
            // if (current->push_cost <= 2)
            //     return (current);
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
    calculate_rotations(stacks->b, candidate->target, &b_dir, &b_rot);
    perform_rotations(stacks, a_rot, a_dir, b_rot, b_dir);
    // rotate_stack(stacks->a, a_rot, a_dir, 'a');
    // rotate_stack(stacks->b, b_rot, b_dir, 'b');
    perform_ps_operations(PB, stacks);
}

void turk_algorithm(t_stacks *stacks)
{
    t_list_node *candidate;
    long min_cost;

    b_stck_psh2_set_up(stacks);
    while (!is_stack_sorted(stacks->a) && (stacks->a->list.size > 3))
    {
        candidate = select_candidate(stacks, &min_cost);
        if (candidate == NULL)
            break;
        process_candidate(stacks, candidate);
        refresh_stacks_all(stacks);
    }
    if (stacks->a->list.size <= 3)
        sorting_algorithms(SORT_THREE_NBRS, stacks);
    while (stacks->b->list.size > 0)
        turk_algorithm_b_to_a(stacks);
    perform_ps_operations(END_TURK, stacks);
}
