#include "circular_stack.h"
#include <stdlib.h>

t_stack *create_circ_stack(void (*del)(void *)) {
    t_stack *s = malloc(sizeof(t_stack));
    if (!s)
        return NULL;
    circ_list_init(&s->list);
    s->del = del;
    return s; 
}