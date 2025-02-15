#include "circular_list.h"
#include <stdlib.h>

void    circ_list_foreach(t_circular_lst *list, void (*f)(void *))
{
    t_list_node *current;
    size_t              i;

    if (list->size == 0)
        return;
    current = list->head;
    i = 0;
    while (i++ < list->size)
    {
        f(current->data);
        current = current->next;
    }
}