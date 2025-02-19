#include "all_headers.h"

long	find_min_data_index(t_stack *stack)

{
	t_list_node *current;
	int	min_val;
	long min_index;
	long index;

	if (!stack || !stack->list.head)
		return -1;
	current = stack->list.head;
	min_val = get_ptr_int(current);
	min_index = 0;
	index = 0;
	while (current != (stack->list.head) || index == 0)
	{
		if (get_ptr_int(current) < min_val)
		{
			min_val = get_ptr_int(current);
			min_index = index;
		}
		current = current->next;
		index++;
		if (current == (stack->list.head) && (index != 0))
			break;
	}
	return (min_index);
}
