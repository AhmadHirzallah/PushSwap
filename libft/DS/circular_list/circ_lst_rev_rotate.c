#include "circular_list.h"

void	circ_lst_rev_rotate(t_circular_lst *list)
{
	if (!list || list->size < 2)
		return ;
	list->head = list->head->prev;
	list->tail = list->tail->prev;
}