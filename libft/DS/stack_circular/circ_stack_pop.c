#include "circular_stack.h"
#include <stdlib.h>

void *pop_circ_stack(t_stack *s)
{
    t_list_node *node;
	void *data;
    
    if (!s || is_circ_stack_empty(s))
    {
        return NULL;
    }
	node = s->list.head;
    data = node->data_s.data.as_ptr;
    circ_list_remove_node(&s->list, node, NULL); // Do not delete data
    return data;
}