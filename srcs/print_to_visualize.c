#include "all_headers.h"

void print_visual_stack(t_stack *a)
{
    t_list_node *node = a->list.head;
    while (node)
    {
        ft_printf("Number: %d\n", *(int *)node->data);
        node = node->next;
    }
}