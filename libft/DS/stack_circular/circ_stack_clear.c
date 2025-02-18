#include "circular_stack.h"
#include <stdlib.h>

void clear_circ_stack(t_stack *s)
{
    if (s)
        circ_list_clear(&s->list, s->del);
}