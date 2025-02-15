#include <stdlib.h>
#include "circular_list.h"

void    circ_list_clear(t_circular_lst *list, void (*del)(void *))
{
    t_list_node *current;
    t_list_node *next;
    size_t              i;

    if (list->size == 0)
        return;
    current = list->head;
    i = 0;
    while (i++ < list->size)
    {
        next = current->next;
        if (del)
            del(current->data);
        free(current);
        current = next;
    }
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}