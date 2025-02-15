#include <stdlib.h>
#include "circular_list.h"

void    circ_list_remove_node(t_circular_lst *list, t_list_node *node, void (*del)(void *))
{
    if (list->size == 0 || !node)
        return;
    if ((list->size == 1) && (list->head == node))
    {
        list->head = NULL;
        list->tail = NULL;
    }
    else
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        if (node == list->head)
            list->head = node->next;
        if (node == list->tail)
            list->tail = node->prev;
    }
    if (del)
        del(node->data);
    free(node);
    list->size--;
}