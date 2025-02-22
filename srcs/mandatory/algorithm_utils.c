/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirzall <ahirzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 19:35:24 by ahirzall          #+#    #+#             */
/*   Updated: 2025/02/21 03:01:55 by ahirzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_headers.h"

long	read_update_indices(t_stack *stack)
{
	t_list_node	*head;
	t_list_node	*current;
	long		length;

	if (!stack || !stack->list.head)
		return (0);
	head = stack->list.head;
	current = head;
	length = 0;
	while (current != head || length == 0)
	{
		current->index = length;
		length++;
		current = current->next;
	}
	return (length);
}

long	read_stack_length(t_stack *stack)
{
	t_list_node	*head;
	t_list_node	*current;
	long		len;

	if (!stack || !stack->list.head)
		return (0);
	head = stack->list.head;
	current = head;
	len = 0;
	while (len == 0 || current != head)
	{
		len++;
		current = current->next;
	}
	return (len);
}

t_list_node	*find_max_node(t_list_node *head)
{
	t_list_node	*current;
	t_list_node	*max_node;
	int			max_val;
	int			current_val;

	if (!head)
		return (NULL);
	max_node = head;
	current = max_node->next;
	max_val = get_node_value(max_node);
	while (current != head)
	{
		current_val = get_node_value(current);
		if (current_val > max_val)
		{
			max_val = current_val;
			max_node = current;
		}
		current = current->next;
	}
	return (max_node);
}


void	sort_two(t_stack *a)
{
	t_list_node	*first;
	t_list_node	*second;
	int			first_val;
	int			second_val;

	if (!a || !a->list.head || a->list.size != 2)
		return ;
	first = a->list.head;
	second = first->next;
	first_val = get_ptr_int(first);
	second_val = get_ptr_int(second);
	if (first_val < second_val)
		return ;
	sa(a);
}

void	sort_three(t_stack *s)
{
	t_list_node	*max;

	if (!s || !s->list.head || s->list.size != 3)
		return ;
	max = find_max_node(s->list.head);
	if (max == s->list.head)
		ra(s);
	else if (s->list.head->next == max)
		rra(s);
	if (get_ptr_int(s->list.head) > get_ptr_int(s->list.head->next))
		sa(s);
}
