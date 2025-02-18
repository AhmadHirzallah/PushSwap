#include "circular_stack.h.h"
#include <stdlib.h>

void stack_clear(t_stack *s)
{
    if (s)
        circ_list_clear(s, NULL);
}
