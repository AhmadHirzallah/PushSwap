#include "all_headers.h"

t_stack	*find_max_in_stck(t_stack *stack)
{
	t_list_node	*max;
	t_list_node		*current;
	int	max_val;
	int	curr_val;

	if (!stack  || stack->list.size == 0)
		return (NULL);
	max = stack->list.head;
	max_val = *(int *)(max->data_s.data.as_ptr);
	current = max->next;
	while (current != stack->list.head)
	{
		curr_val = *(int *)(current->data_s.data.as_ptr);
		if (curr_val > max_val)
		{
			max_val = curr_val;
			max = current;
		}
		current = current->next;
	} 
	return (max);
}