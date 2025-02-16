#include "libft.h"

char	*str_space(int *chr)
{
	if (*chr == ' ' || *chr == '\n' || *chr == '\t' \
		|| *chr == '\r' || *chr == '\f' || *chr == '\v')
		return ((char *)chr);
	return (NULL); 
}