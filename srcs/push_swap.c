/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirzall <ahirzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 19:34:36 by ahirzall          #+#    #+#             */
/*   Updated: 2025/02/21 01:39:41 by ahirzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "circular_list.h"
// #include "libft.h"
// #include "ft_printf.h"
// #include "utils.h"

#include "all_headers.h"

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
	
	size = stacks->a->list.size;
	if (size == 2)
		sorting_algorithms(SORT_TWO_NBRS, stacks);
	else if (size == 3)
		sorting_algorithms(SORT_THREE_NBRS, stacks);
	else if (size == 5)
		sorting_algorithms(SORT_FIVE_NBRS, stacks);
	else
		sorting_algorithms(TURK_ALGO, stacks);
		
}

int	push_swap(int *argc, char **argv[])
{
	t_stacks *stacks;
	t_utils_helpers *helpers;
	int result;

	stacks = NULL;
	helpers = NULL;
	if (!argv[0][0])
		return (__WRNG_ARGS_NBR__);
	result = process_pushswap_data(&stacks, &helpers, argc, argv);
	if (result != __SUCC__)
	{
		terminate_ps(stacks, helpers);
		return (result);
	}
	perform_ps(stacks);
	

	/*********************** 				TESTS 				*********************/
	/*********************** 									*********************/

	// print_visual_1stack(stacks->a, "Stack A :) :) ");
	// print_visual_2stacks(stacks->a, "A Stack", stacks->b, "B Stack");
	// ft_printf("Stack a size: (%d)\nStack b size: (%d)\n", stacks->a->list.size,
	// 	stacks->b->list.size);

	// perform_ps_operations(SA, stacks);
	// print_visual_2stacks(stacks->a, "A Stack", stacks->b, "B Stack");
	// ft_printf("Stack a size: (%d)\nStack b size: (%d)\n", stacks->a->list.size,
	// 	stacks->b->list.size);

	// perform_ps_operations(PB, stacks);
	// print_visual_2stacks(stacks->a, "A Stack", stacks->b, "B Stack");
	// ft_printf("Stack a size: (%d)\nStack b size: (%d)\n", stacks->a->list.size,
	// 	stacks->b->list.size);
	// perform_ps_operations(PB, stacks);
	// print_visual_2stacks(stacks->a, "A Stack", stacks->b, "B Stack");
	// ft_printf("Stack a size: (%d)\nStack b size: (%d)\n", stacks->a->list.size,
	// 	stacks->b->list.size);

	// perform_ps_operations(SB, stacks);
	// print_visual_2stacks(stacks->a, "A Stack", stacks->b, "B Stack");
	// ft_printf("Stack a size: (%d)\nStack b size: (%d)\n", stacks->a->list.size,
	// 	stacks->b->list.size);

	// perform_ps_operations(SS, stacks);
	// print_visual_2stacks(stacks->a, "A Stack", stacks->b, "B Stack");
	// ft_printf("Stack a size: (%d)\nStack b size: (%d)\n", stacks->a->list.size,
	// 	stacks->b->list.size);

	// perform_ps_operations(SS, stacks);
	// print_visual_2stacks(stacks->a, "A Stack", stacks->b, "B Stack");
	// ft_printf("Stack a size: (%d)\nStack b size: (%d)\n", stacks->a->list.size,
	// 	stacks->b->list.size);

	// perform_ps_operations(RA, stacks);
	// print_visual_2stacks(stacks->a, "A Stack", stacks->b, "B Stack");
	// ft_printf("Stack a size: (%d)\nStack b size: (%d)\n", stacks->a->list.size,
	// 	stacks->b->list.size);
	// perform_ps_operations(RA, stacks);
	// perform_ps_operations(RA, stacks);
	// perform_ps_operations(RB, stacks);
	// print_visual_2stacks(stacks->a, "A Stack", stacks->b, "B Stack");
	// ft_printf("Stack a size: (%d)\nStack b size: (%d)\n", stacks->a->list.size,
	// 	stacks->b->list.size);

	// perform_ps_operations(RR, stacks);
	// print_visual_2stacks(stacks->a, "A Stack", stacks->b, "B Stack");
	// ft_printf("Stack a size: (%d)\nStack b size: (%d)\n", stacks->a->list.size,
	// 	stacks->b->list.size);
	// perform_ps_operations(RR, stacks);
	// perform_ps_operations(RR, stacks);
	// print_visual_2stacks(stacks->a, "A Stack", stacks->b, "B Stack");
	// ft_printf("Stack a size: (%d)\nStack b size: (%d)\n", stacks->a->list.size,
	// 	stacks->b->list.size);

	// perform_ps_operations(PB, stacks);
	// perform_ps_operations(PB, stacks);
	// perform_ps_operations(RRR, stacks);
	// print_visual_2stacks(stacks->a, "A Stack", stacks->b, "B Stack");
	// ft_printf("Stack a size: (%d)\nStack b size: (%d)\n", stacks->a->list.size,
	// 	stacks->b->list.size);
	// perform_ps_operations(RRA, stacks);
	// print_visual_2stacks(stacks->a, "A Stack", stacks->b, "B Stack");
	// ft_printf("Stack a size: (%d)\nStack b size: (%d)\n", stacks->a->list.size,
	// 	stacks->b->list.size);
	// perform_ps_operations(RRB, stacks);
	// print_visual_2stacks(stacks->a, "A Stack", stacks->b, "B Stack");
	// ft_printf("Stack a size: (%d)\nStack b size: (%d)\n", stacks->a->list.size,
	// 	stacks->b->list.size);
	// perform_ps_operations(PA, stacks);
	// print_visual_2stacks(stacks->a, "A Stack", stacks->b, "B Stack");
	// ft_printf("Stack a size: (%d)\nStack b size: (%d)\n", stacks->a->list.size,
	// 	stacks->b->list.size);
	return (__SUCC__);
}