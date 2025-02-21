#include "all_headers.h"

t_list_node *find_target_for_b(t_list_node *b_node, t_stack *a)
{
    int             b_val;
    long            best_match;
    t_list_node     *target;
    t_list_node     *current;

    b_val = get_ptr_int(b_node);
    best_match = LONG_MAX;
    target = NULL;
    current = a->list.head;
    while (1)
    {
        if (get_node_value(current) > b_val && get_node_value(current) < best_match)
        {
            best_match = get_node_value(current);
            target = current;
        }
        current = current->next;
        if (current == a->list.head)
            break;
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