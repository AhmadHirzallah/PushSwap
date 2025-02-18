#include "circular_stack.h"
#include <stdlib.h>

void *peek_circ_stack(const t_stack *s)
{
    if (!s || s->list.size == 0)
        return (NULL);
    return (s->list.head->data_s.data.as_ptr);
}