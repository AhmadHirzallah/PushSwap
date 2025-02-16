/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirzall <ahirzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 13:35:45 by ahirzall          #+#    #+#             */
/*   Updated: 2025/02/15 13:45:04 by ahirzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "circular_list.h"
# include "libft.h"
# include "push_swap.h"
# include "utils.h"

int	push_swap(int *argc , char **argv[]);
short	prepare_strs_handler(t_utils_helpers *helpers);
short	run_validation_checks(t_stack *list, long nbr);
short	extract_nbrs_process(t_stacks *stacks, t_utils_helpers *helpers);
void print_visual_1stack(t_stack *stack, char *stack_name);
void print_visual_2stacks(t_stack *a, char *na, t_stack *b, char *nb);

#endif