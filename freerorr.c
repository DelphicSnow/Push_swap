/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freerorr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkajanek <tkajanek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 19:03:38 by tkajanek          #+#    #+#             */
/*   Updated: 2023/04/01 18:41:36 by tkajanek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_nodes(t_node *head)
{
	t_node	*current;
	t_node	*next;

	current = head;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

void	free_stack(t_stack *stack)
{
	if (stack != NULL)
	{
		if (stack->head != NULL)
			free_nodes(stack->head);
		free(stack);
	}
}

void	ft_error(t_stack *stack_a, t_stack *stack_b)
{
	free_stack(stack_a);
	free_stack(stack_b);
	write(2, "Error\n", 6);
	exit (1);
}
