/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_checks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirzall <ahirzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 19:34:43 by ahirzall          #+#    #+#             */
/*   Updated: 2025/02/19 19:34:43 by ahirzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_headers.h"


static short	check_is_duplicate(t_stack *stack, int nbr)
{
	t_list_node	*current;
	size_t	count;

	if (!stack)
		return (__ERR_IN_LST_DUP_CHCK__);
	current = stack->list.head;
	count = stack->list.size;
	while (count--)
	{
		if (*(int *)current->data_s.data.as_ptr == nbr)
			return (__ERR_THERE_IS_DUPLIC__);
		current = current->next;
	}
	return (__SUCC__);
}

short	run_validation_checks(t_stack *list, __int128_t nbr)
{
	if (nbr > INT_MAX || nbr < INT_MIN)
		return (__WRNG_INT_RANGE__);
	return (check_is_duplicate(list, (int)nbr));
}
