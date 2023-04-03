/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort_for_45.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkajanek <tkajanek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 20:06:22 by tkajanek          #+#    #+#             */
/*   Updated: 2023/04/01 16:28:37 by tkajanek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_cost_of_rotation(t_stack *stack, int wanted_value)
{
	t_node	*current;
	int		i;

	i = 0;
	current = stack->head;
	if (stack->head == NULL)
		return (0);
	while (i < stack->size)
	{
		if (current->value == wanted_value)
			return (i);
		i++;
		current = current->next;
	}
	return (0);
}

static int	find_min_value(t_stack *stack)
{
	int		min;
	t_node	*current;
	int		i;

	i = 0;
	min = __INT_MAX__;
	current = stack->head;
	if (stack->head == NULL)
		return (0);
	while (i < stack->size)
	{
		if (current->value < min)
			min = current->value;
		i++;
		current = current->next;
	}
	return (min);
}

static void	do_selection_sort(t_stack *stack_a, t_stack *stack_b, int min_value,
int cost_to_rotate)
{
	int	i;

	i = 0;
	while (stack_a->size > 3)
	{
		min_value = find_min_value(stack_a);
		cost_to_rotate = get_cost_of_rotation(stack_a, min_value);
		if (cost_to_rotate == 1)
			operation_sa(stack_a);
		else if (cost_to_rotate > 1)
		{
			if (cost_to_rotate > stack_a->size / 2)
			{
				while (i++ < stack_a->size - cost_to_rotate)
					operation_rra(stack_a);
			}
			if (cost_to_rotate <= stack_a->size / 2)
			{
				while (i++ < cost_to_rotate)
					operation_ra(stack_a);
			}
		}
		i = 0;
		operation_pb(stack_a, stack_b);
	}
}

void	selection_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	min_value;
	int	cost_to_rotate;
	int	size_before_sort;

	size_before_sort = stack_a->size;
	min_value = 0;
	cost_to_rotate = 0;
	do_selection_sort(stack_a, stack_b, min_value, cost_to_rotate);
	sort_3(stack_a, size_before_sort);
	while (stack_b->size > 0)
		operation_pa(stack_a, stack_b);
}
