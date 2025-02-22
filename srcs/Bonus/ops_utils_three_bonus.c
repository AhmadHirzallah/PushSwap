/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_utils_three_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirzall <ahirzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 17:56:27 by ahirzall          #+#    #+#             */
/*   Updated: 2025/02/22 19:16:08 by ahirzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circular_stack.h"
#include <stdlib.h>
#include "pushswap_bonus.h"
#include "dlist.h"

/* Swap the first two elements of stack a */
void	sa_bonus(t_d_stack *a)
{
	t_value_data	*tmp;

	if (a == NULL || a->size < 2)
		return ;

	tmp = a->head->data;
	a->head->data = a->head->next->data;
	a->head->next->data = tmp;
	// ft_printf("sa\n");
}

/* Swap the first two elements of stack b */
void	sb_bonus(t_d_stack *b)
{
	t_value_data	*tmp;

	if (b == NULL || b->size < 2)
		return ;

	tmp = b->head->data;
	b->head->data = b->head->next->data;
	b->head->next->data = tmp;
	// ft_printf("sb\n");
}

/* Swap the first two elements of both stacks a and b */
void	ss_bonus(t_d_stack *a, t_d_stack *b)
{
	sa_bonus(a);
	sb_bonus(b);
	// ft_printf("ss\n");
}
