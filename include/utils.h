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
	__FAIL_ADDING_STACKA_NBR__
};

typedef struct s_utils_helpers
{
	char	**input;
	long	input_size;
	t_queue				dsply_prnt_hndler;
}			t_utils_helpers;

typedef struct s_stacks
{
	t_stack *a;
	t_stack	*b;

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
	SB
}					 t_stacks_oprs;

#endif