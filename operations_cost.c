/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_cost.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkajanek <tkajanek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:35:20 by tkajanek          #+#    #+#             */
/*   Updated: 2023/03/21 16:20:34 by tkajanek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_cost_of_rotation(t_stack *stack, int wanted_value)
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
	return(0);
}
/*
int	find_max_value(t_stack *stack)
{
	int	max;
	t_node	*current;
	int		i;

	i = 0;
	max = INT_MIN;//vychytat min
	current = stack->head;
	if (stack->head == NULL)
		return (0); // vychytat error
	while (i < stack->size)
	{
		if (current->value > max)
			max = current->value;
		i++;
		current = current->next;
	}
	return (max);
}
*/
int	find_min_value(t_stack *stack)
{
	int	min;
	t_node	*current;
	int		i;

	i = 0;
	min = __INT_MAX__;
	current = stack->head;
	if (stack->head == NULL)
		return (0); // vychytat error
	while (i < stack->size)
	{
		if (current->value < min)
			min = current->value;
		i++;
		current = current->next;
	}
	return (min);
}