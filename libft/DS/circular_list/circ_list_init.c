#include "circular_list.h"
#include "libft.h"

void    circ_list_init(t_circular_lst *list)
{
    ft_bzero(list, sizeof(t_circular_lst));
}