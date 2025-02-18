#include "circular_stack.h"
#include <stdlib.h>

short push_circ_stack(t_stack *s, void *data)
{
    if (!s)
    {
        return -1;
    }
    return (circ_list_insert_beginning(&s->list, data));
}