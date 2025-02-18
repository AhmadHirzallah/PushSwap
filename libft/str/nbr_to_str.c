#include "libft.h"

static void handle_negative(__int128_t nbr, short *is_negative, unsigned __int128 *unbr)
{
    if (nbr < 0)
    {
		*unbr = (unsigned __int128) (-1 * nbr);
        *is_negative = 1;
    }
    else
    {
        *is_negative = 0;
		*unbr = (unsigned __int128) nbr;
    }
}

static size_t extract_digits(unsigned __int128 num, char *buffer)
{
    size_t total_size;
	
	total_size = 0;
    while (num > 0)
    {
        buffer[total_size++] = '0' + (num % 10);
        num /= 10;
    }
    return total_size;
}

static	void	reverse_digits(char *bfr, size_t len)
{
	size_t i;
	size_t j;
	char	temp;

	i = 0;
	j = len - 1;
	while (i < j)
	{
		temp = bfr[i];
		bfr[i] = bfr[j];
		bfr[j] = temp;
		i++;
		j++;	
	}
}

static void	fill_result_nbr(char **result, int is_negative, char *bfr, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (is_negative)
		*result[i++] = '-';
	while (j < len)
		*result[i++] = bfr[j++];
	*result[i] = '\0';
}

char *nbr_to_str(__int128_t nbr)
{
	char	bfr[40];
	size_t	len;
	size_t	total_size;
	short		is_negative;
	unsigned __int128	unbr;
	char	*result;

	total_size = 0;
	is_negative = 0;
	if (nbr == 0)
		return (ft_strdup("0"));
	handle_negative(nbr, &is_negative, &unbr);
	len = extract_digits(unbr, bfr);
	reverse_digits(bfr, total_size);
	total_size = len + is_negative + 1;
	result = malloc(total_size);
	if (!result)
		return (NULL);
	fill_result_nbr(&result, is_negative, bfr, len);
	return (result);
}