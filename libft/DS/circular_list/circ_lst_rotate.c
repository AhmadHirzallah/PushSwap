#include "circular_list.h"

void	circ_lst_rotate(t_circular_lst *list)
{
	if (!list || list->size < 2)
		return ;
	list->head = list->head->next;
	list->tail = list->tail->next;
}