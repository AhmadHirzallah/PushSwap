/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirzall <ahirzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 18:56:19 by ahirzall          #+#    #+#             */
/*   Updated: 2025/02/22 19:08:40 by ahirzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/all_headers.h"
#include "push_swap.h"
#include "pushswap_bonus.h"

short	is_valid_nbr_str(const char *str)
{
	if (!str || !*str)
		return (__ERR_INVALID_NBR_CHR__);
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (__ERR_INVALID_NBR_CHR__);
		str++;
	}
	return (__SUCC__);
}

static short	process_tokens_from_str(char *input, t_d_stack *a)
{
	__int128_t		nbr;
	short			validation;
	char			*next_nbr_str;
	t_value_data	*data;

	next_nbr_str = str_tok_sttc(input, " \n\t");
	while (next_nbr_str)
	{
		validation = is_valid_nbr_str(next_nbr_str);
		if (validation != __SUCC__)
			return (validation);
		nbr = ft_atoint128(next_nbr_str);
		validation = run_valid_nbr_checks(a, nbr);
		if (validation != __SUCC__)
			return (validation);
		data = malloc(sizeof(t_value_data));
		data->as_int = (int)nbr;
		validation = dlist_insert_end(a, data);
		if (validation == -1)
			return (validation);
		next_nbr_str = str_tok_sttc(NULL, " \n\t,;");
	}
	return (__SUCC__);
}

short	extract_nbrs(t_stacks_bonus *ss)
{
	size_t	i;
	short	error;

	i = 0;
	while (ss->helpers.nbrs_str[i])
	{
		error = process_tokens_from_str(ss->helpers.nbrs_str[i], ss->a);
		if (error != __SUCC__)
			return (error);
		i++;
	}
	return (__SUCC__);
}

short	intitalize_structs(t_stacks_bonus **ss, int argc, char **argv)
{
	*ss = ft_calloc(1, sizeof(t_stacks_bonus));
	if (!(*ss))
		return (__FAIL_CALLOC_BONUS__);
	(*ss)->total_count = --argc;
	(*ss)->helpers.nbrs_str = ++argv;
	(*ss)->a = ft_calloc(1, sizeof(t_d_stack));
	if (!(*ss)->a)
		return (__FAIL_CALLOC_BONUS__);
	(*ss)->b = ft_calloc(1, sizeof(t_d_stack));
	if (!(*ss)->a)
		return (__FAIL_CALLOC_BONUS__);
	return (__SUCC__);
}

int	main(int argc, char **argv)
{
	t_stacks_bonus *ss;
	enum e_rtrns rtrn_result;

	if (argc == 1)
		return (__WRNG_ARGS_NBR__);
	rtrn_result = intitalize_structs(&ss, argc, argv);
	rtrn_result = extract_nbrs(ss);
	if (rtrn_result != __SUCC__)
	{
		free_stacks_bonus(ss);
		return (rtrn_result);
	}
	// bonus_print_visual_2dstacks(ss->a, "Stack a", ss->b, "Stack b");
	check_user_input_ops(ss);
	return (display_checker_result(ss));
}
