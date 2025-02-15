#include "circular_list.h"

void    circ_list_swap_first_2(t_circular_lst *list)
{
    t_list_node *first;
    t_list_node *second;
    void                *tmp;

    if (list->size < 2)
        return;
    first = list->head;
    second = first->next;
    tmp = first->data;
    first->data = second->data;
    second->data = tmp;
}