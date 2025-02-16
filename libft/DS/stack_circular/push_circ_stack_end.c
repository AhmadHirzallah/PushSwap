#include "circular_stack.h"
#include <stdlib.h>

short push_circ_stack_end(t_stack *s, void *data)
{
    if (!s)
        return -1;
    return (circ_list_insert_end(&s->list, data));
}