#include "circular_stack.h"
#include <stdlib.h>

void rev_rotate_circ_stack(t_stack *s)
{
    if (s && s->list.size > 1)
	{
        s->list.head = s->list.head->prev;
		s->list.tail = s->list.tail->prev;
	}
}