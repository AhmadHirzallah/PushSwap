/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirzall <ahirzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 20:18:08 by ahirzall          #+#    #+#             */
/*   Updated: 2025/02/22 20:24:56 by ahirzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_BONUS_H
# define PUSHSWAP_BONUS_H

# include "dlist.h"
# include "ft_printf.h"
# include "libft.h"

typedef t_dlist		t_d_stack;

typedef struct s_d_helperss
{
	char			**nbrs_str;
	long			input_count;
}					t_d_helperss;

typedef struct s_d_stackss
{
	t_d_stack		*a;
	t_d_stack		*b;
	long			total_count;
	t_d_helperss	helpers;

}					t_stacks_bonus;

short				extract_nbrs(t_stacks_bonus *stacks);
int					get_value(t_dlist_node *node);
short				run_valid_nbr_checks(t_d_stack *s, __int128_t nbr);
short				intitalize_structs(t_stacks_bonus **ss, int argc,
						char **argv);
void				bonus_print_visual_2dstacks(t_d_stack *a, char *na,
						t_d_stack *b, char *nb);
void				check_user_input_ops(t_stacks_bonus *ss);
void				ra_bonus(t_d_stack *a);
void				rb_bonus(t_d_stack *b);
void				rr_bonus(t_d_stack *a, t_d_stack *b);
void				rra_bonus(t_d_stack *a);
void				rrb_bonus(t_d_stack *b);
t_dlist_node		*dlist_pop_front_bonus(t_d_stack *stack);
void				dlist_push_front_bonus(t_d_stack *stack,
						t_dlist_node *node);
void				rrr_bonus(t_d_stack *a, t_d_stack *b);
void				pa_bonus(t_d_stack *a, t_d_stack *b);
void				pb_bonus(t_d_stack *a, t_d_stack *b);
void				sa_bonus(t_d_stack *a);
void				sb_bonus(t_d_stack *b);
void				ss_bonus(t_d_stack *a, t_d_stack *b);
bool				is_sorted_dlist_bonus(t_d_stack *stack);
void				free_d_stack_bonus(t_d_stack *stack);
void				free_stacks_bonus(t_stacks_bonus *ss);
void				check_result_bonus(t_d_stack *a_stack, t_d_stack *b_stack);
int					display_checker_result(t_stacks_bonus *ss);

#endif
