/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirzall <ahirzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 17:20:50 by ahirzall          #+#    #+#             */
/*   Updated: 2025/02/22 21:31:51 by ahirzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circular_stack.h"
#include "dlist.h"
#include "get_next_line.h"
#include "pushswap_bonus.h"
#include "utils.h"
#include <stdlib.h>

/*
   perform_ps_operations_bns:
   Executes the corresponding operation on the stacks
   based on the provided op code.
   Note: The stacks parameter is a double pointer;
	we dereference it to access each stack.
*/
static void	perform_ps_operations_bns(t_stacks_oprs op, t_stacks_bonus **stacks)
{
	if (op == RA)
		ra_bonus((*stacks)->a);
	else if (op == RB)
		rb_bonus((*stacks)->b);
	else if (op == RR)
		rr_bonus((*stacks)->a, (*stacks)->b);
	else if (op == RRA)
		rra_bonus((*stacks)->a);
	else if (op == RRB)
		rrb_bonus((*stacks)->b);
	else if (op == RRR)
		rrr_bonus((*stacks)->a, (*stacks)->b);
	else if (op == PA)
		pa_bonus((*stacks)->a, (*stacks)->b);
	else if (op == PB)
		pb_bonus((*stacks)->a, (*stacks)->b);
	else if (op == SA)
		sa_bonus((*stacks)->a);
	else if (op == SB)
		sb_bonus((*stacks)->b);
	else if (op == SS)
		ss_bonus((*stacks)->a, (*stacks)->b);
}

/*
   handle_cmd: Compares the given command string with valid operations and calls
   perform_ps_operations_bns() accordingly.
   Returns 1 if the command is recognized and executed, or 0 otherwise.
*/
static short	handle_cmd(char *cmd, t_stacks_bonus **ss)
{
	if (!str_cmpr(cmd, "sa\n"))
		perform_ps_operations_bns(SA, ss);
	else if (!str_cmpr(cmd, "sb\n"))
		perform_ps_operations_bns(SB, ss);
	else if (!str_cmpr(cmd, "ss\n"))
		perform_ps_operations_bns(SS, ss);
	else if (!str_cmpr(cmd, "ra\n"))
		perform_ps_operations_bns(RA, ss);
	else if (!str_cmpr(cmd, "rb\n"))
		perform_ps_operations_bns(RB, ss);
	else if (!str_cmpr(cmd, "rr\n"))
		perform_ps_operations_bns(RR, ss);
	else if (!str_cmpr(cmd, "rra\n"))
		perform_ps_operations_bns(RRA, ss);
	else if (!str_cmpr(cmd, "rrb\n"))
		perform_ps_operations_bns(RRB, ss);
	else if (!str_cmpr(cmd, "rrr\n"))
		perform_ps_operations_bns(RRR, ss);
	else if (!str_cmpr(cmd, "pa\n"))
		perform_ps_operations_bns(PA, ss);
	else if (!str_cmpr(cmd, "pb\n"))
		perform_ps_operations_bns(PB, ss);
	else
		return (__INVALID_CMD__);
	return (__SUCC__);
}

/*
   check_user_input_ops: Continuously reads a command from standard input
   (using get_next_line) and processes it until no more input is available.
*/
void	check_user_input_ops(t_stacks_bonus *ss)
{
	char	*cmd;

	cmd = get_next_line(0);
	while (cmd)
	{
		if (handle_cmd(cmd, &ss) != __SUCC__)
		{
			ft_printf("Error\n");
			free(cmd);
			free_stacks_bonus(ss);
			exit(__INVALID_CMD__);
		}
		if (cmd)
			free(cmd);
		cmd = get_next_line(0);
	}
}
