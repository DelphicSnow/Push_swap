/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkajanek <tkajanek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:07:34 by tkajanek          #+#    #+#             */
/*   Updated: 2023/04/02 17:32:04 by tkajanek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
#include <stdio.h>
void print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	t_node *current = stack_a->head;
	printf ("stack_a:");
    while (current != NULL)
	{
        printf("%d ", current->value);
        current = current->next;
    }
	printf("\n");
	if (stack_b)
	{
		current = stack_b->head;
		printf ("stack_b:");
		while (current != NULL)
		{
			printf("%d ", current->value);
			current = current->next;
		}
	}
}
*/
static int	is_sorted(t_stack *stack)
{
	t_node	*current;

	current = stack->head;
	while (current->next != NULL)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	free_stack(stack);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1)
		return (0);
	stack_a = NULL;
	if (argc == 2)
		stack_a = parse_string(stack_a, &argc, argv);
	else if (argc > 2)
	{
		if (!check_input(argv, argc))
			ft_error(stack_a, NULL);
		stack_a = parse_arguments_for_stack_a(argc, argv);
		if (!stack_a)
			ft_error(stack_a, NULL);
	}
	is_sorted(stack_a);
	stack_b = initialize_stack();
	if (!stack_b)
		ft_error(stack_a, stack_b);
	assign_index(stack_a);
	sort_stack (stack_a, stack_b, argc);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
