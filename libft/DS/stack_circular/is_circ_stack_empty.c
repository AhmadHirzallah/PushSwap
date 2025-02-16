#include "circular_stack.h"
#include <stdlib.h>

short is_circ_stack_empty(const t_stack *s)
{
	if (s->list.size == 0)
		return (1);
	return (0);
}
/*
short is_circ_stack_empty(const t_stack *s)
{
    return (s ? (s->size == 0) : 1);
}
*/