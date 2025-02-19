/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirzall <ahirzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 19:34:55 by ahirzall          #+#    #+#             */
/*   Updated: 2025/02/19 19:34:56 by ahirzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "all_headers.h"

void ra(t_stack *a)
{
	rotate_circ_stack(a);
	ft_printf("ra\n");
}

void rb(t_stack *b)
{
	rotate_circ_stack(b);
	ft_printf("rb\n");
}

void rr(t_stack *a, t_stack *b)
{
	rotate_circ_stack(a);
	rotate_circ_stack(b);
	ft_printf("rr\n");
}