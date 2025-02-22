/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirzall <ahirzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 19:35:11 by ahirzall          #+#    #+#             */
/*   Updated: 2025/02/19 19:35:12 by ahirzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_headers.h"

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = ft_calloc(1, sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->del = del_node_data;
	return (stack);
}

short	init_stacks_a_b(t_stacks *stacks)
{
	stacks->a = init_stack();
	if (!stacks->a)
		return (__STACK_MALLOC_FAIL__);
	stacks->b = init_stack();
	if (!stacks->b)
		return (__STACK_MALLOC_FAIL__);
	return (__SUCC__);
}

short	init_helpers(t_utils_helpers **helpers)
{
	*helpers = ft_calloc(1, sizeof(t_utils_helpers));
	if (!*helpers)
		return (__HELPERS_MALLOC_FAIL__);
	return (__SUCC__);
}

short	initialize_ps(t_stacks **stacks, t_utils_helpers **helpers)
{
	*stacks = ft_calloc(1, sizeof(t_stacks));
	if (!*stacks)
		return (__WRNG_INIT_CALLOC__);
	if (init_helpers(helpers) != __SUCC__)
		return (__HELPERS_MALLOC_FAIL__);
	if (!*helpers)
		return (__WRNG_INIT_CALLOC__);
	if (init_stacks_a_b(*stacks) != __SUCC__)
		return (__STACK_MALLOC_FAIL__);
	return (__SUCC__);
}
