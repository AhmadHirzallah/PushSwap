/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_manipulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirzall <ahirzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 19:35:15 by ahirzall          #+#    #+#             */
/*   Updated: 2025/02/20 07:35:27 by ahirzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_headers.h"

void	turk_set_flag(t_list_node *tln, t_stack_flags flag)
{
	tln->flags |= flag;
}

void	turk_unset_flag(t_list_node *tln, t_stack_flags flag)
{
	tln->flags &= ~flag;
}

short	turk_has_flag(t_list_node *tln, t_stack_flags flag)
{
	return ((tln->flags & flag) != 0);
}
