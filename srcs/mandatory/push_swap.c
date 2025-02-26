/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirzall <ahirzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 19:34:36 by ahirzall          #+#    #+#             */
/*   Updated: 2025/02/22 21:42:47 by ahirzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circular_list.h"
#include "libft.h"
#include "ft_printf.h"
#include "utils.h"
#include "push_swap.h"

static void	free_allocated_input(t_utils_helpers *helpers)
{
	int	index;
	int	size;

	index = 0;
	size = helpers->input_size;
	while (index < size)
	{
		if (helpers->malloc_flags != NULL)
		{
			if (helpers->malloc_flags[index] == 1)
			{
				free(helpers->input[index]);
				helpers->input[index] = NULL;
			}
		}
		index++;
	}
}

static int	free_helpers(t_utils_helpers **helpers)
{
	t_utils_helpers	*temp;

	if (helpers == NULL)
		return (0);
	temp = *helpers;
	if (temp == NULL)
		return (0);
	free_allocated_input(temp);
	if (temp->malloc_flags != NULL)
	{
		free(temp->malloc_flags);
		temp->malloc_flags = NULL;
	}
	free(temp);
	*helpers = NULL;
	return (0);
}

int	process_pushswap_data(t_stacks **stacks, t_utils_helpers **helpers,
		int *argc, char ***argv)
{
	short	rtrn;

	rtrn = initialize_ps(stacks, helpers);
	if (rtrn != __SUCC__)
		return (rtrn);
	(*helpers)->input_size = (long)(--(*argc));
	(*helpers)->input = ++(*argv);
	if (argc == 0)
		return (__WRNG_ARGS_NBR__);
	prepare_strs_handler(*helpers);
	rtrn = extract_nbrs_process(*stacks, *helpers);
	if (rtrn != __SUCC__)
		return (rtrn);
	return (__SUCC__);
}

static void	perform_ps(t_stacks *stacks)
{
	__int128	size;

	refresh_stacks_all(stacks);
	size = stacks->a->list.size;
	if (size == 2)
		sorting_algorithms(SORT_TWO_NBRS, stacks);
	else if (size == 3)
		sorting_algorithms(SORT_THREE_NBRS, stacks);
	else if (size <= 5)
		sorting_algorithms(SORT_FIVE_NBRS, stacks);
	else
		sorting_algorithms(TURK_ALGO, stacks);
}

int	push_swap(int *argc, char **argv[])
{
	t_stacks		*stacks;
	t_utils_helpers	*helpers;
	int				result;

	stacks = NULL;
	helpers = NULL;
	result = process_pushswap_data(&stacks, &helpers, argc, argv);
	if (result != __SUCC__)
	{
		free_helpers(&helpers);
		terminate_ps(stacks, result);
		return (result);
	}
	if (is_stack_sorted(stacks->a))
	{
		free_helpers(&helpers);
		terminate_ps(stacks, result);
		return (__SUCC__);
	}
	perform_ps(stacks);
	free_helpers(&helpers);
	return (terminate_ps(stacks, __SUCC__));
	return (__SUCC__);
}
