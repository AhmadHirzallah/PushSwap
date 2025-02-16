#include "circular_stack.h"
#include <stdlib.h>

size_t get_circ_stack_size(const t_stack *s)
{
	if (s)
		return (s->list.size);
	return (0);
}
/*
size_t stack_size(const t_stack *s)
{
    return (s ? s->size : 0);
}
*/