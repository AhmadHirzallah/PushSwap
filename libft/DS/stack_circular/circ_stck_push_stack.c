#include "circular_stack.h"

void	circ_stck_push_stack(t_stack *dest, t_stack *src)
{
	t_list_node *node;

	node = circ_stck_remove_top_node(src);
	if (node)
		 circ_stck_insert_node_at_top(dest, node);
}