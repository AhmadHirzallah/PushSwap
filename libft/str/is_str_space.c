#include "libft.h"

short	is_str_space(int chr)
{
	return (chr == ' ' || chr == '\n' || chr == '\t' \
		|| chr == '\r' || chr == '\f' || chr == '\v');
}