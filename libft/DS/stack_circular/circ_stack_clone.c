#include "circular_stack.h"
#include <stdlib.h>

t_stack *circ_stack_clone(t_stack *s, void *(*copy)(void *), void (*del)(void *)) {
    if (!s || !copy)
        return NULL;
    t_stack *clone = create_circ_stack(del);
    if (!clone)
        return NULL;
    t_list_node *current = s->list.head;
    for (size_t i = 0; i < s->list.size; i++) {
        void *data_copy = copy(current->data_s.data.as_ptr);
        if (!data_copy || circ_list_insert_end(&clone->list, data_copy) != 0) {
            if (data_copy && del)
                del(data_copy);
            destroy_circ_stack(clone);
            return NULL;
        }
        current = current->next;
    }
    return clone;
}