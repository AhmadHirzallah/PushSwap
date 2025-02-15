#include <stdlib.h>
#include "circular_list.h"

int     circ_list_insert_end(t_circular_lst *list, void *data)
{
    t_list_node *new_node;

    new_node = malloc(sizeof(t_list_node));
    if (!new_node)
        return (-1);
    new_node->data = data;
    if (list->size == 0)
    {
        new_node->next = new_node;
        new_node->prev = new_node;
        list->head = new_node;
    }
    else
    {
        new_node->next = list->head;
        new_node->prev = list->tail;
        list->tail->next = new_node;
        list->head->prev = new_node;
    }
    list->tail = new_node;
    list->size++;
    return (0);
}