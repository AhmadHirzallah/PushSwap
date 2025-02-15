// #include "circular_list.h"
// #include "libft.h"
// #include "ft_printf.h"
// #include "utils.h"

#include "all_headers.h"

static short	init_stacks2(t_stacks *stacks)
{
	stacks->a = init_stack();
	if (!stacks->a)
		return (__STACK_MALLOC_FAIL__);
	stacks->b = init_stack();
	if (!stacks->b)
		return (__STACK_MALLOC_FAIL__);
	return (__SUCC__);
}

static t_circular_lst	*init_stack()
{
	t_circular_lst	*stack;

	stack = ft_calloc(1, sizeof(t_circular_lst));
	if (!stack)
		return (NULL);
	return (stack);
}

static short	initialize_ps(t_stacks *stacks, t_utils_helpers *helpers)
{
			//So, after calling ft_calloc, the memory for stacks (of type t_stacks) will look like this:
			//
				// stacks->a.head = NULL;
				// stacks->a.tail = NULL;
				// stacks->a.size = 0;

				// stacks->b.head = NULL;
				// stacks->b.tail = NULL;
				// stacks->b.size = 0;
			// But, since a.head and a.tail will point to dynamic list nodes (which themselves are dynamically allocated), you need to separately allocate memory for these nodes.

	stacks = ft_calloc(1, sizeof(t_stacks));
	if (!stacks)
		return (__WRNG_INIT_CALLOC__);
	if (init_stacks2(stacks) != __SUCC__)
		return (__STACK_MALLOC_FAIL__);
}

int	push_swap(t_stacks *stacks, t_utils_helpers *helpers)
{
	initialize_ps(stacks, helpers);

	size_t i = 0;
	while(helpers->input[i])
	{
		str_nullify_delimiters(helpers->input[i], "\n\t ,;");
		i++;
	}
	



}