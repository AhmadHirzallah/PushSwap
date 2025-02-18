#include "circular_stack.h"
#include <stdlib.h>

void rotate_circ_stack(t_stack *s)
{
    if (s && s->list.size > 1)
	{
        s->list.head = s->list.head->next;
		s->list.tail = s->list.tail->next;
	}
}