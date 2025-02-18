/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirzall <ahirzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 13:35:26 by ahirzall          #+#    #+#             */
/*   Updated: 2025/02/15 17:03:44 by ahirzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include <limits.h>
# include "queue.h"
# include "circular_stack.h"



enum		e_returns
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
	__FAIL_ADDING_STACKA_NBR__
};

typedef struct s_utils_helpers
{
	char	**input;
	short	*malloc_flags;
	long	input_size;
	t_queue				dsply_prnt_hndler;
}			t_utils_helpers;

typedef struct s_stacks
{
	t_stack *a;
	t_stack	*b;
    int         a_median;
    int         b_median;
    size_t      total_ops;

}	t_stacks;

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
	SS
}					 t_stacks_oprs;

typedef enum	e_stack_flags
/*
	ABOVE_MEDIAN    = 1 << 0,  // 0b00000001
    BELOW_MEDIAN    = 1 << 1,  // 0b00000010
    CHEAPEST        = 1 << 2,  // 0b00000100
    TARGET_NODE     = 1 << 3   // 0b00001000
*/
{
	ABOVE_MEDIAN    = 1 << 0,
    BELOW_MEDIAN    = 1 << 1,
    CHEAPEST        = 1 << 2,
    TARGET_NODE     = 1 << 3
}	t_stack_flags;

typedef struct s_turk_algo_data
{
	long index;
	long	nbr;
	long	push_cost;
	unsigned int	flags;
}	t_turk_algo_data;



#endif