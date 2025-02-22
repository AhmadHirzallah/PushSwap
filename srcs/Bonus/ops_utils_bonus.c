/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirzall <ahirzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 17:47:06 by ahirzall          #+#    #+#             */
/*   Updated: 2025/02/22 19:16:00 by ahirzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circular_stack.h"
#include "dlist.h"
#include "pushswap_bonus.h"
#include <stdlib.h>

#include "circular_stack.h"
#include <stdlib.h>
#include "pushswap_bonus.h"
#include "dlist.h"

/* Pop the first node from the doubly linked list (stack) */
t_dlist_node	*dlist_pop_front_bonus(t_d_stack *stack)
{
	t_dlist_node	*node;

	if (stack == NULL || stack->size == 0)
		return (NULL);

	node = stack->head;
	stack->head = node->next;
	if (stack->head != NULL)
	{
		stack->head->prev = NULL;
	}
	else
	{
		stack->tail = NULL;
	}
	node->next = NULL;
	node->prev = NULL;
	stack->size--;
	return (node);
}

/* Push a node to the front of the doubly linked list (stack) */
void	dlist_push_front_bonus(t_d_stack *stack, t_dlist_node *node)
{
	if (stack == NULL || node == NULL)
		return ;

	node->next = stack->head;
	node->prev = NULL;
	if (stack->head != NULL)
	{
		stack->head->prev = node;
	}
	else
	{
		stack->tail = node;
	}
	stack->head = node;
	stack->size++;
}

/* Reverse rotate both stacks a and b */
void	rrr_bonus(t_d_stack *a, t_d_stack *b)
{
	rra_bonus(a);
	rrb_bonus(b);
	// ft_printf("rrr\n");
}

/* Push the top node from stack b to stack a */
void	pa_bonus(t_d_stack *a, t_d_stack *b)
{
	t_dlist_node	*node;

	if (a == NULL || b == NULL)
		return ;

	node = dlist_pop_front_bonus(b);
	if (node == NULL)
		return ;

	dlist_push_front_bonus(a, node);
	// ft_printf("pa\n");
}

/* Push the top node from stack a to stack b */
void	pb_bonus(t_d_stack *a, t_d_stack *b)
{
	t_dlist_node	*node;

	if (a == NULL || b == NULL)
		return ;

	node = dlist_pop_front_bonus(a);
	if (node == NULL)
		return ;

	dlist_push_front_bonus(b, node);
	// ft_printf("pb\n");
}
