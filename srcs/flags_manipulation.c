/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_manipulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirzall <ahirzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 19:35:15 by ahirzall          #+#    #+#             */
/*   Updated: 2025/02/19 19:35:15 by ahirzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_headers.h"

void turk_set_flag(t_turk_algo_data *tad, t_stack_flags flag)
{
    tad->flags |= flag;
}

void turk_unset_flag(t_turk_algo_data *tad, t_stack_flags flag)
{
    tad->flags &= ~flag;
}

short turk_has_flag(const t_turk_algo_data *tad, t_stack_flags flag)
{
    return ((tad->flags & flag) != 0);
}