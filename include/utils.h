/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirzall <ahirzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 22:15:05 by ahirzall          #+#    #+#             */
/*   Updated: 2025/02/20 07:21:45 by ahirzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H

# define UTILS_H

# include "circular_stack.h"
# include "queue.h"
# include <limits.h>

enum				e_returns
{
	__SUCC__,
	__WRNG_ARGS_NBR__,
	__WRNG_INIT_CALLOC__,
	__STACK_MALLOC_FAIL__,
	__HELPERS_MALLOC_FAIL__,
	__WRNG_INT_RANGE__,
	__ERR_INVALID_NBR_CHR__,
	__ERR_IN_LST_DUP_CHCK__,
	__ERR_THERE_IS_DUPLIC__,
	__FAIL_MALLOC_INT_NBR__,
	__FAIL_MALLOC_FLAGS__,
	__FAIL_ADDING_STACKA_NBR__,
	__FAIL,
	__FAIL_CALLOC_BONUS__
};

typedef struct s_utils_helpers
{
	char			**input;
	short			*malloc_flags;
	long			input_size;
	t_queue			dsply_prnt_hndler;
}					t_utils_helpers;

typedef struct s_stacks
{
	t_stack			*a;
	t_stack			*b;
	int				a_middle;
	int				b_middle;
	size_t			total_ops;
}					t_stacks;
typedef enum s_stacks_oprs
{
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
	PA,
	PB,
	SA,
	SB,
	SS,
	ROTATION,
	REV_ROTATION,
	END_TURK
}					t_stacks_oprs;

/*
	ABOVE_MEDIAN    = 1 << 0,  // 0b00000001
	BELOW_MEDIAN    = 1 << 1,  // 0b00000010
	CHEAPEST        = 1 << 2,  // 0b00000100
	TARGET_NODE     = 1 << 3   // 0b00001000
*/
typedef enum e_stack_flags
{
	ABOVE_MEDIAN = 1 << 0,
	BELOW_MEDIAN = 1 << 1,
	CHEAPEST = 1 << 2,
	TARGET_NODE = 1 << 3,
	IS_STCK_SORTED = 1 << 4
}					t_stack_flags;

/*
- Every (a) node need a `target_node` from (b)!! 
- The (target) node is the closest smaller number to (a) node value
- if no (closest smaller) number is found ; then the (target node) is (max node)
	t_list_node	*node;      Node in stack A 
	t_list_node	*target;    Target node in stack B 
	long		cost;       Combined rotations needed 
	long		a_rot;      Rotations needed in A 
	long		b_rot;      Rotations needed in B 
*/
typedef struct s_turk_algo_data
{
    t_list_node    *node;
    t_list_node    *target;
    long           cost;
	t_stacks_oprs	a_direction;
    long           a_rot;
	t_stacks_oprs	b_direction;
    long           b_rot;
}					t_turk_algo_data;


typedef enum e_sorting_cases
{
	SORT_TWO_NBRS,
	SORT_THREE_NBRS,
	SORT_FIVE_NBRS,
	TURK_ALGO
}					t_sorting_cases;

// void turkish_sort(t_stack *a, t_stack *b);
#endif