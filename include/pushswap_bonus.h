#ifndef PUSHSWAP_BOUNUS_H
# define PUSHSWAP_BOUNUS_H

#include "dlist.h"
#include "libft.h"
#include "ft_printf.h"



typedef t_dlist t_d_stack;

typedef struct s_d_helperss
{
	char **nbrs_str;
	long input_count;
}						t_d_helperss;

typedef struct s_d_stackss
{
	t_d_stack *a;
	t_d_stack *b;
	long	total_count;
	t_d_helperss	helpers;
	
}	t_stacks_bonus;



short	extract_nbrs(t_stacks_bonus *stacks);
int	get_value(t_dlist_node *node);
short	run_valid_nbr_checks(t_d_stack *s, __int128_t nbr);
short	 intitalize_structs(t_stacks_bonus **ss, int argc, char **argv);
void bonus_print_visual_2dstacks(t_d_stack *a, char *na, t_d_stack *b, char *nb);



#endif