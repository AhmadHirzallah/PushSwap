#include "all_headers.h"

short	prepare_strs_handler(t_utils_helpers *helpers)
{
	size_t i;

	i = 0;
	while(helpers->input[i])
	{
		helpers->input[i] = ft_strtrim(helpers->input[i], "\n\t ,;");
		str_nullify_delimiters(helpers->input[i], "\n\t ,;");
		i++;
	}
	return (0);
}

static short	add_into_stack(t_stack *a, int nbr)
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

static short is_valid_integer_str(const char *str)
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
	long	nbr;
	short	validation;
	size_t i;

	i = 0;
	while (input[i])
	{
		while (input[i] == '\0')
			++i;
		if (input[i] == '\0')
			break;;
		validation = is_valid_integer_str(&input[i]);
		if (validation != __SUCC__)
		nbr = ft_atol(&input[i]);
		validation = run_validation_checks(a, nbr);
		if (validation != __SUCC__)
			return (validation);
		validation = add_into_stack(a, (int)nbr);
		if (validation != __SUCC__)
			return (validation);
		while (input[i] != '\0')
			++i;
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
		{
			// terminate_program();
			return (error);
		}
		i++;
	}
	return (__SUCC__);	
}