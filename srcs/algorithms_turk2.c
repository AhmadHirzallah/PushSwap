#include "all_headers.h"

void set_target_for_b(t_stack *a, t_stack *b)
{
    t_list_node *current;

    current = b->list.head;
    while (current)
    {
        current->target = find_target_for_b(current, a);
        current = current->next;
		if (current == b->list.head)
			break;
    }
}

static long compute_push_cost_b_to_a(t_list_node *b_node, 
                                          t_list_node *a_target, 
                                          t_stacks *s)
{
    t_stacks_oprs  a_dir;
    t_stacks_oprs  b_dir;
    long           a_rot;
    long           b_rot;
    long           cost;

    calculate_rotations(s->b, b_node, &b_dir, &b_rot);
    calculate_rotations(s->a, a_target, &a_dir, &a_rot);
    if (a_dir == b_dir)
    {
        if (a_rot > b_rot)
            cost = a_rot;
        else
            cost = b_rot;
    }
    else
        cost = a_rot + b_rot;
    return (cost);
}

t_list_node *select_candidate_b_to_a(t_stacks *s, long *min_cost)
{
    t_list_node *current;
    t_list_node *candidate;
    ssize_t     i;

    candidate = NULL;
    *min_cost = LONG_MAX;
    current = s->b->list.head;
    i = -1;
    while (++i < (ssize_t)s->b->list.size)
    {
        current->push_cost = compute_push_cost_b_to_a(current, 
                                                          current->target, 
                                                          s);
        if (current->push_cost < *min_cost)
        {
            *min_cost = current->push_cost;
            candidate = current;
            if (current->push_cost <= 2)
                return (candidate);
        }
        current = current->next;
    }
    return (candidate);
}

static void process_candidate_b_to_a(t_stacks *s, t_list_node *candidate)
{
    t_stacks_oprs  a_dir;
    t_stacks_oprs  b_dir;
    long           a_rot;
    long           b_rot;

    calculate_rotations(s->b, candidate, &b_dir, &b_rot);
    rotate_stack(s->b, b_rot, b_dir, 'b');
    calculate_rotations(s->a, candidate->target, &a_dir, &a_rot);
    rotate_stack(s->a, a_rot, a_dir, 'a');
    perform_ps_operations(PA, s);
}

void turk_algorithm_b_to_a(t_stacks *s)
{
    t_list_node *candidate;
    long        min_cost;
    t_stacks_oprs  a_dir;
    long           a_rot;

    refresh_stacks_all(s);
    set_target_for_b(s->a, s->b);
    while (s->b->list.size > 0)
    {
        candidate = select_candidate_b_to_a(s, &min_cost);
        if (candidate == NULL)
            break;
        process_candidate_b_to_a(s, candidate);
        refresh_stacks_all(s);
        set_target_for_b(s->a, s->b);
    }
	calculate_rotations(s->a, find_max_node(s->a->list.head), &a_dir, &a_rot);
	if (a_dir == ROTATION)
		a_dir = RA;
	else
		a_dir = RRA;
    while (s->a->list.head != find_min_node(s->a->list.head))
		perform_ps_operations(a_dir, s);
}
