/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkajanek <tkajanek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:07:27 by tkajanek          #+#    #+#             */
/*   Updated: 2023/03/17 19:48:23 by tkajanek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *parse_arguments(int argc, char **argv)
{
	int		i;
	int		value;
	t_stack	*stack;
	t_node	*current_node;

	stack = initialize_stack(stack);
	i = argc - 1;
	value = 0;
 	while (i > 0)
	{
		value = ft_atoi(argv[i]);
		//if
		current_node = create_node(stack, value);
		//if
		i--;
		//current_node->rotate_cost = i;
	}

	return(stack);
}

t_node *create_node(t_stack *stack, int value)
{
	t_node	*new_node;
	
	new_node = malloc(sizeof(t_node) * 1);
	//if
	//exit
	new_node->value = value;
	new_node->next = stack->head;
	stack->head = new_node;
	stack->size++;
	return (new_node);
}

t_stack *initialize_stack(t_stack *stack)
{
	t_stack	*tmp_stack;

	tmp_stack = malloc(sizeof(t_stack) * 1);
	//if
	tmp_stack->head = NULL;
	tmp_stack->size = 0;
	return (tmp_stack);
}