#include "push_swap.h"
#include "all_headers.h"

void pa(t_stack *a, t_stack *b)
{
	circ_stck_push_stack(a, b);
	ft_printf("pa\n");
}

void pb(t_stack *a, t_stack *b)
{
	circ_stck_push_stack(b, a);
	ft_printf("pb\n");
}

void sa(t_stack *a)
{
	swap_stack_top_2(a);
	ft_printf("sa\n");
}

void sb(t_stack *b)
{
	swap_stack_top_2(b);
	ft_printf("sb\n");
}

void ss(t_stack *a, t_stack *b)
{
	swap_stack_top_2(a);
	swap_stack_top_2(b);
	ft_printf("ss\n");
}
