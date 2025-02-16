#include "circular_stack.h"

short stack_iter_on_data(t_stack *s, int (*f)(void *))
{
    t_list_node *current;
	
    if (!s || !f)
    {
        return -1;
    }
	current = s->list.head;
    size_t i = 0;
    while (i < s->list.size) {
        if (f(current->data) != 0)
            return 1;
        current = current->next;
        i++;
    }
    return 0;
}
