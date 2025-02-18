#include "circular_list.h"

void    circ_list_swap_first_2(t_circular_lst *list)
{
    t_list_node *first;
    t_list_node *second;
    t_value       tmp;

    if (list->size < 2)
        return;
    first = list->head;
    second = first->next;
    tmp = first->data_s;
    first->data_s= second->data_s;
    second->data_s = tmp;
}