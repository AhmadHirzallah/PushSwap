#include "circular_list.h"
#include "libft.h"
#include "utils.h"
#include "push_swap.c"

int main(int argc , char *argv[])
{
	if (argc == 1)
	{
		ft_putstr_fd("Error\n", 2);
		return (__WRNG_ARGS_NBR__);
	}
	push_swap(argc , argv);

	return (__SUCC__);
}