#include "all_headers.h"


static short	check_is_duplicate(t_stack *stack, int nbr)
{
	t_list_node	*current;
	size_t	count;

	if (!stack)
		return (__ERR_IN_LST_DUP_CHCK__);
	current = stack->list.head;
	count = stack->list.size;
	while (count--)
	{
		if (*(int *)current->data == nbr)
			return (__ERR_THERE_IS_DUPLIC__);
		current = current->next;
	}
	return (__SUCC__);
}

short	run_validation_checks(t_stack *list, long nbr)
{
	if (nbr > INT_MAX && nbr < INT_MIN)
	{
		ft_putstr_fd("Error\n", 2);
		return (__WRNG_INT_RANGE__);
	}
	return (check_is_duplicate(list, (int)nbr));
}