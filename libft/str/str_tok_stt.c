/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_tok.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirzall <ahirzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 14:53:17 by ahirzall          #+#    #+#             */
/*   Updated: 2025/02/15 16:39:02 by ahirzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

char	*str_tok_stt(char *input, const char *delimiters)
/*
This Function will create tokens but in many rounds; every round it will return one tocken!!
*/
{
	static char	*current_pos = NULL;
	char		*tocken_start;

	if (input)
		current_pos = input;
	if (!current_pos)
		return (NULL);
	while (*current_pos && ft_strchr(delimiters, *current_pos))
		current_pos++;
	if (!*current_pos)
	{
		current_pos = NULL;
		return (NULL);
	}
	tocken_start = current_pos;
	while (*current_pos && !ft_strchr(delimiters, *current_pos))
		current_pos++;
	if (!*current_pos)
	{
		*current_pos = '\0';
		return (NULL);
	}
	else
		current_pos = NULL;
	return (tocken_start);
}
