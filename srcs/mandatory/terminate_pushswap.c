/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate_pushswap.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirzall <ahirzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 19:34:40 by ahirzall          #+#    #+#             */
/*   Updated: 2025/02/19 22:25:36 by ahirzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_headers.h"

void	del_node_data(void *data)
{
	if (data)
	{
		free(data);
		data = NULL;
	}
}

static void	free_stacks_helper(t_stacks *stacks)
{
	if (!stacks)
		return ;
	if (stacks->a)
	{
		circ_list_clear(&stacks->a->list, stacks->a->del);
		free(stacks->a);
		stacks->a = NULL;
	}
	if (stacks->b)
	{
		circ_list_clear(&stacks->b->list, stacks->b->del);
		free(stacks->b);
		stacks->b = NULL;
	}
	if (stacks)
		free(stacks);
}

// static void	free_helpers_malc_flg(t_utils_helpers *helpers)
// {
// 	if ((helpers)->dsply_prnt_hndler.list)
// 	{
// 		dlist_destroy((helpers)->dsply_prnt_hndler.list);
// 		free((helpers)->dsply_prnt_hndler.list);
// 		(helpers)->dsply_prnt_hndler.list = NULL;
// 	}
// }

// static void free_utils_helper(t_utils_helpers **helpers)
// {
// 	long i;

// 	if (!helpers || !*helpers)
// 		return ;
// 	if ((*helpers)->input)
// 	{
// 		i = 0;
// 		while (i < (*helpers)->input_size && (*helpers)->input[i])
// 		{
// 			if ((*helpers)->malloc_flags[i])

// 				free((*helpers)->input[i]);
// 			i++;
// 		}
// 		(*helpers)->input = NULL;
// 	}
// }

// int	terminate_ps(t_stacks *stacks, t_utils_helpers *helpers)
int	terminate_ps(t_stacks *stacks, enum e_returns result)
{
	// free_helpers_malc_flg(helpers);
	// helpers = NULL;
	free_stacks_helper(stacks);
	stacks = NULL;
	if (result != __SUCC__)
		ft_putstr_fd("Error\n", 2);
	return (result);
}
