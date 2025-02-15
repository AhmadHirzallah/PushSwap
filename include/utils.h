#ifndef UTILS_H
# define UTILS_H

# ifndef MAX_INT 2147483647
#  define MAX_INT 2147483647
# endif

# ifndef SMALLEST_INT -2147483648
#  define SMALLEST_INT -2147483648
# endif

enum	e_returns
{
	__SUCC__,
	__WRNG_ARGS_NBR__
};

typedef	struct s_utils_helpers
{
	char *str;
}	t_utils_helpers;






#endif