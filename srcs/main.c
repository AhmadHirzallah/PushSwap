/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirzall <ahirzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 19:35:04 by ahirzall          #+#    #+#             */
/*   Updated: 2025/02/19 19:35:04 by ahirzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "push_swap.h" 
#include "all_headers.h"

int main(int argc , char *argv[])

{
	short result;
	
	result = push_swap(&argc, &argv);
	return (result);
}