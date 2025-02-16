// #include "circular_list.h"
// #include "libft.h"
// #include "ft_printf.h"
// #include "utils.h"

#include "all_headers.h"

static t_stack	*init_stack()
{
	t_stack	*stack;

	stack = ft_calloc(1, sizeof(t_stack));
	if (!stack)
		return (NULL);
	return (stack);
}
static short	init_stacks_a_b(t_stacks *stacks)
{
	stacks->a = init_stack();
	if (!stacks->a)
		return (__STACK_MALLOC_FAIL__);
	stacks->b = init_stack();
	if (!stacks->b)
		return (__STACK_MALLOC_FAIL__);
	return (__SUCC__);
}



static short	init_helpers(t_utils_helpers *helpers)
{
	helpers = ft_calloc(1, sizeof(t_utils_helpers));
	if (!helpers)
		return (__HELPERS_MALLOC_FAIL__);
	dlist_init(helpers->dsply_prnt_hndler.list, NULL);
	return (__SUCC__);
}

static short	initialize_ps(t_stacks *stacks, t_utils_helpers *helpers)
/*
			So, after calling ft_calloc, the memory for stacks (of type t_stacks) will look like this:
			
				stacks->a.head = NULL;
				stacks->a.tail = NULL;
				stacks->a.size = 0;

				stacks->b.head = NULL;
				stacks->b.tail = NULL;
				stacks->b.size = 0;
			But, since a.head and a.tail will point to dynamic list nodes (which themselves are dynamically allocated), you need to separately allocate memory for these nodes.
*/
{
	stacks = ft_calloc(1, sizeof(t_stacks));
	if (!stacks)
		return (__WRNG_INIT_CALLOC__);
	helpers = ft_calloc(1, sizeof(t_utils_helpers));
	if (!helpers)
		return (__WRNG_INIT_CALLOC__);
	if (init_stacks_a_b(stacks) != __SUCC__)
		return (__STACK_MALLOC_FAIL__);
	if (init_helpers(helpers) != __SUCC__)
		return (__HELPERS_MALLOC_FAIL__);
	return (__SUCC__);
}

int	push_swap(int *argc , char **argv[])
{
	short	rtrn;
	t_stacks	*stacks;
	t_utils_helpers *helpers;

	rtrn = initialize_ps(stacks, helpers);
	if (rtrn != __SUCC__)
	{
		// free_all();
		return (rtrn);
	}
	helpers->input_size = (long)(--(*argc));
	helpers->input = ++(*argv);
	if (argc == 0)
		return (__WRNG_ARGS_NBR__);
	if (!argv[0][0])
	{
		ft_putstr_fd("Error\n", 2);
		return (__WRNG_ARGS_NBR__);
	}
	prepare_strs_handler(helpers);
	extract_nbrs_process(stacks, helpers);
	return (__SUCC__);
}