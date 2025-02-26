/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirzall <ahirzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 17:35:39 by ahirzall          #+#    #+#             */
/*   Updated: 2025/02/22 21:28:45 by ahirzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circular_stack.h"
#include "dlist.h"
#include "pushswap_bonus.h"
#include <stdlib.h>

/* Rotate stack a: move its head node to the tail */
void	ra_bonus(t_d_stack *a)
{
	t_dlist_node	*temp;

	if (a == NULL || a->size < 2)
		return ;
	temp = a->head;
	a->head = a->head->next;
	a->head->prev = NULL;
	a->tail->next = temp;
	temp->prev = a->tail;
	temp->next = NULL;
	a->tail = temp;
}

/* Rotate stack b: move its head node to the tail */
void	rb_bonus(t_d_stack *b)
{
	t_dlist_node	*temp;

	if (b == NULL || b->size < 2)
		return ;
	temp = b->head;
	b->head = b->head->next;
	b->head->prev = NULL;
	b->tail->next = temp;
	temp->prev = b->tail;
	temp->next = NULL;
	b->tail = temp;
}

/* Rotate both stacks a and b */
void	rr_bonus(t_d_stack *a, t_d_stack *b)
{
	ra_bonus(a);
	rb_bonus(b);
}

/* Reverse rotate stack a: move its tail node to the head */
void	rra_bonus(t_d_stack *a)
{
	t_dlist_node	*temp;

	if (a == NULL || a->size < 2)
		return ;
	temp = a->tail;
	a->tail = a->tail->prev;
	a->tail->next = NULL;
	temp->prev = NULL;
	temp->next = a->head;
	a->head->prev = temp;
	a->head = temp;
}

/* Reverse rotate stack b: move its tail node to the head */
void	rrb_bonus(t_d_stack *b)
{
	t_dlist_node	*temp;

	if (b == NULL || b->size < 2)
		return ;
	temp = b->tail;
	b->tail = b->tail->prev;
	b->tail->next = NULL;
	temp->prev = NULL;
	temp->next = b->head;
	b->head->prev = temp;
	b->head = temp;
}
