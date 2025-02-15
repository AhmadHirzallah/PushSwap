// #include "push_swap.h" 
#include "all_headers.h"

int main(int argc , char *argv[])
{
	t_stacks	stacks;
	t_utils_helpers helpers;

	helpers.input_size = --argc;
	argv++;
	if (argc == 0)
	{
		ft_putstr_fd("Error\n", 2);
		return (__WRNG_ARGS_NBR__);
	}
	helpers.input = argv;
	push_swap(&stacks, &helpers);

	return (__SUCC__);
}