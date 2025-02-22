#include "pushswap_bonus.h"
#include "../mandatory/all_headers.h"

int	get_value(t_dlist_node *node)
{
	return (node->data->as_int);
}

static short	check_is_duplicate(t_d_stack *s, int nbr)
{
	t_dlist_node	*current;
	size_t		count;

	if (!s)
		return (__SUCC__);
	current = s->head;
	count = s->size;
	while (count--)
	{
		if (get_value(s->head) == nbr)
			return (__ERR_THERE_IS_DUPLIC__);
		current = current->next;
	}
	return (__SUCC__);
}

short	run_valid_nbr_checks(t_d_stack *s, __int128_t nbr)
{
	if (nbr > INT_MAX || nbr < INT_MIN)
		return (__WRNG_INT_RANGE__);
	return (check_is_duplicate(s, (int)nbr));
}
