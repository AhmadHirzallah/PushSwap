/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_to_visualize.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirzall <ahirzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 19:34:49 by ahirzall          #+#    #+#             */
/*   Updated: 2025/02/19 19:34:49 by ahirzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_headers.h"

void	print_visual_1stack(t_stack *stack, char *stack_name)
{
	t_list_node	*current;

	if (!stack || !stack->list.head)
		return ;
	// Print stack name
	ft_printf("===== %s =====\n", stack_name);
	current = stack->list.head;
	while (1)
	{
		ft_printf("|  %d  |\n", *((int *)current->data_s.data.as_ptr));
		ft_printf("------\n");
		current = current->next;
		if (current == stack->list.head)
			return ;
	}
}

static void	print_headers(char *na, char *nb)
{
	ft_printf("   %-8s     |   %-8s   \n", na, nb);
	ft_printf("----------------------------\n");
}

static void	print_stack_row(t_list_node *ca, t_list_node *cb)
{
	int	va;
	int	vb;

	va = 0;
	if (ca != NULL)
		va = *((int *)ca->data_s.data.as_ptr);
	vb = 0;
	if (cb != NULL)
		vb = *(int *)cb->data_s.data.as_ptr;
	ft_printf("|  %3d  |  <->  |  %3d  |\n", va, vb);
}

static void	update_currents(t_list_node **ca, t_list_node **cb, t_list_node *ha,
		t_list_node *hb)
{
	if (*ca != NULL)
	{
		if ((*ca)->next == ha)
			*ca = NULL;
		else
			*ca = (*ca)->next;
	}
	if (*cb != NULL)
	{
		if ((*cb)->next == hb)
			*cb = NULL;
		else
			*cb = (*cb)->next;
	}
}

void	print_visual_2stacks(t_stack *a, char *na, t_stack *b, char *nb)
{
	t_list_node *ca;
	t_list_node *cb;
	t_list_node *ha;
	t_list_node *hb;

	ca = NULL;
	if (a != NULL)
	{
		ca = a->list.head;
	}
	cb = NULL;
	if (b != NULL)
	{
		cb = b->list.head;
	}
	ha = ca;
	hb = cb;
	print_headers(na, nb);
	while (ca != NULL || cb != NULL)
	{
		print_stack_row(ca, cb);
		update_currents(&ca, &cb, ha, hb);
	}
	ft_printf("Stack a size: (%d)\nStack b size: (%d)\n", a->list.size,
		b->list.size);
}