/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result_cleanup_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirzall <ahirzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 18:56:12 by ahirzall          #+#    #+#             */
/*   Updated: 2025/02/22 21:33:46 by ahirzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/all_headers.h"
#include "circular_stack.h"
#include "dlist.h"
#include "push_swap.h"
#include "pushswap_bonus.h"
#include <stdlib.h>

/*
   is_sorted_dlist_bonus:
   Efficiently checks if the doubly linked list
   (stack) is sorted in ascending order.
   It uses two pointers (one starting at the head and the other at the tail)
   and performs iterations for half of the list length.
*/
bool	is_sorted_dlist_bonus(t_d_stack *stack)
{
	t_dlist_node	*left;
	size_t			i;

	if (!stack || stack->size <= 1)
		return (true);
	left = stack->head;
	i = 0;
	while (i < stack->size)
	{
		if (left->next && get_value(left) > get_value(left->next))
			return (false);
		left = left->next;
		i++;
	}
	return (true);
}

/*
   free_d_stack_bonus:
   Frees all nodes in a doubly linked list (stack)
   along with the data held in each node.
   It uses the stack's del function if provided,
	otherwise it frees the node's data directly.
*/
void	free_d_stack_bonus(t_d_stack *stack)
{
	t_dlist_node	*current;
	t_dlist_node	*next;

	if (!stack)
		return ;
	current = stack->head;
	while (current)
	{
		next = current->next;
		if (stack->del)
			stack->del(current->data);
		else
			free(current->data);
		free(current);
		current = next;
	}
	free(stack);
}

void	free_stacks_bonus(t_stacks_bonus *ss)
{
	if (!ss)
		return ;
	if (ss->a)
		free_d_stack_bonus(ss->a);
	if (ss->b)
		free_d_stack_bonus(ss->b);
	free(ss);
}

void	check_result_bonus(t_d_stack *a_stack, t_d_stack *b_stack)
{
	if (is_sorted_dlist_bonus(a_stack) && (!b_stack || b_stack->size == 0))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}

int	display_checker_result(t_stacks_bonus *ss)
{
	int	result;

	if (is_sorted_dlist_bonus(ss->a) && (!ss->b || ss->b->size == 0))
	{
		ft_printf("OK\n");
		result = __SUCC__;
	}
	else
	{
		ft_putstr_fd("KO\n", 2);
		result = __CHECKER_ERR__;
	}
	free_stacks_bonus(ss);
	return (result);
}
