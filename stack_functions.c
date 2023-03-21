/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkajanek <tkajanek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:07:27 by tkajanek          #+#    #+#             */
/*   Updated: 2023/03/21 16:20:37 by tkajanek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *parse_arguments_for_stack_a(int argc, char **argv)
{
	int		i;
	int		value;
	t_stack	*stack;
	t_node	*current_node;

	stack = initialize_stack();
	if (!stack)
		return (NULL);
	i = argc - 1;
	value = 0;
 	while (i > 0)
	{
		value = (int)ft_atoi(argv[i]);
		current_node = create_node(stack, value);
		if (!current_node)
			return (NULL);
		i--;
	}
	return(stack);
}

t_node *create_node(t_stack *stack, int value)
{
	t_node	*new_node;
	
	new_node = malloc(sizeof(t_node) * 1);
	if (!new_node)
		return (NULL);	
	new_node->value = value;
	new_node->next = stack->head;
	stack->head = new_node;
	stack->size++;
	return (new_node);
}

t_stack *initialize_stack(void)
{
	t_stack	*tmp_stack;

	tmp_stack = malloc(sizeof(t_stack) * 1);
	if (!tmp_stack)
		return (NULL);
	tmp_stack->head = NULL;
	tmp_stack->size = 0;
	return (tmp_stack);
}