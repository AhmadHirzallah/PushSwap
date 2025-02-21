/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirzall <ahirzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 19:34:52 by ahirzall          #+#    #+#             */
/*   Updated: 2025/02/20 20:23:28 by ahirzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_headers.h"
#include "push_swap.h"

void	rra(t_stack *a)
{
	rev_rotate_circ_stack(a);
	ft_printf("rra\n");
}

void	rrb(t_stack *b)
{
	rev_rotate_circ_stack(b);
	ft_printf("rrb\n");
}

void	rrr(t_stack *a, t_stack *b)
{
	rev_rotate_circ_stack(a);
	rev_rotate_circ_stack(b);
	ft_printf("rrr");
}

void	perform_ps_operations(t_stacks_oprs op, t_stacks *stacks)
{
	if (op == RA)
		ra(stacks->a);
	else if (op == RB)
		rb(stacks->b);
	else if (op == RR)
		rr(stacks->a, stacks->b);
	else if (op == RRA)
		rra(stacks->a);
	else if (op == RRB)
		rrb(stacks->b);
	else if (op == RRR)
		rrr(stacks->a, stacks->b);
	else if (op == PA)
		pa(stacks->a, stacks->b);
	else if (op == PB)
		pb(stacks->a, stacks->b);
	else if (op == SA)
		sa(stacks->a);
	else if (op == SB)
		sb(stacks->b);
	else if (op == SS)
		ss(stacks->a, stacks->b);
}
