#include "circular_stack.h"
#include <stdlib.h>

void destroy_circ_stack(t_stack *s) {
    if (!s)
        return;
    circ_list_clear(&s->list, s->del);
    free(s);
}