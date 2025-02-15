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
#include <limits.h>



enum		e_returns
{
	__SUCC__,
	__WRNG_ARGS_NBR__,
	__WRNG_INIT_CALLOC__,
	__STACK_MALLOC_FAIL__
};

typedef struct s_utils_helpers
{
	char	**input;
	long	input_size;
}			t_utils_helpers;

typedef struct s_stacks
{
	t_circular_lst	*a;
	t_circular_lst	*b;

}	t_stacks;


#endif