/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirzall <ahirzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 19:34:46 by ahirzall          #+#    #+#             */
/*   Updated: 2025/02/19 19:34:46 by ahirzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_headers.h"

short	prepare_strs_handler(t_utils_helpers *helpers)
{
	size_t i;
	char	*trimmed;

	i = 0;
	if (helpers->input)
		while (helpers->input[i])
			i++;
		
	helpers->input_size = i;
	helpers->malloc_flags = ft_calloc(helpers->input_size, sizeof(short));
	if (!helpers->malloc_flags)
		return (__FAIL_MALLOC_FLAGS__);
	i = 0;
	while(helpers->input[i])
	{
		trimmed = ft_strtrim(helpers->input[i], "\n\t ,;");
		if (trimmed != helpers->input[i])
		{
			helpers->malloc_flags[i] = 1;
			helpers->input[i] = trimmed;
		}
		i++;
	}
	return (0);
}

static short	add_into_stack(t_stack *a, int nbr)
/*
Store the integer directly in the t_value union instead of allocating memory.
 *
 * This approach avoids allocating a separate int on the heap and stores the integer value
 * directly in the union. If you only need to handle integers, this method is simpler and
 * removes the need to dereference pointers when retrieving the value.
 *         t_value val;
 *         val.type = VAL_INT;         // Mark the type as integer.
 *         val.data.as_int = nbr;      // Store the integer directly.
 *          if (push_circ_stack_end(a, &val))  // Assuming push_circ_stack_end now expects a pointer to t_value.
*/
{
	int	*int_ptr;
	
	int_ptr = malloc(sizeof(int));
	if (!int_ptr)
		return (__FAIL_MALLOC_INT_NBR__);
	*int_ptr = nbr;
	if (push_circ_stack_end(a, int_ptr))
	{
		free(int_ptr);
		return (__FAIL_ADDING_STACKA_NBR__);
	}
	return (__SUCC__);
}

static short is_valid_nbr_str(const char *str)
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


static short	process_tokens_from_str(char *input, t_stack *a)
{
	__int128_t	nbr;
	short	validation;
	char	*next_nbr_str;

	next_nbr_str = str_tok_sttc(input, " \n\t,;");
	while (next_nbr_str)
	{
		validation = is_valid_nbr_str(next_nbr_str);
		if (validation != __SUCC__)
			return (validation);
		nbr = ft_atoint128(next_nbr_str);
		validation = run_validation_checks(a, nbr);
		if (validation != __SUCC__)
			return (validation);
		validation = add_into_stack(a, (int)nbr);
		if (validation != __SUCC__)
			return (validation);

		next_nbr_str = str_tok_sttc(NULL, " \n\t,;");
	}
	return (__SUCC__);
}


short	extract_nbrs_process(t_stacks *stacks, t_utils_helpers *helpers)
{
	size_t i;
	short	error;

	i = 0;
	while (helpers->input[i])
	{
		error = process_tokens_from_str(helpers->input[i], stacks->a);
		if (error != __SUCC__)
			return (error);
		i++;
	}
	return (__SUCC__);	
}