#include "circular_stack.h"
#include <stdlib.h>

void swap_stack_top_2(t_stack *s)
{
    circ_list_swap_first_2(&s->list);
}