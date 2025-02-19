#include "circular_stack.h"

void circ_stck_insert_node_at_top(t_stack *s, t_list_node *node)
{
	if (!s || !node)
		return ;
	if (s->list.size == 0)
	{
		node->next = node;
		node->prev = node;
		s->list.head = node;
		s->list.tail =  node;
	}
	else
	{
		node->next = s->list.head;
		node->prev = s->list.tail;
		s->list.tail->next = node;
        s->list.head->prev = node;
        s->list.head = node;
	}
	s->list.size++;
}
