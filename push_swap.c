/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkajanek <tkajanek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:07:34 by tkajanek          #+#    #+#             */
/*   Updated: 2023/03/21 16:20:30 by tkajanek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include <stdio.h> 

/*
void	sort_stack (t_stack *stack_a, t_stack *stack_b)
{
	int	i = 0;

	while (stack_a->head->next != NULL && i < 20)
	{
		if (stack_b->head != NULL)
		{
			if (stack_b->head-> next != NULL) 
			{
				if (stack_a->head->value < stack_a->head->next->value && stack_b->head->value < stack_b->head->next->value)
					operation_ss(stack_a, stack_b);
			}
		}
		if (stack_a->head->next != NULL) 
		{
			if (stack_a->head->value < stack_a->head->next->value)
				operation_sa(stack_a);
			else
				operation_pa (stack_a, stack_b);
		}
		if (stack_b->head != NULL)
		{
			if (stack_b->head-> next != NULL) 
			{
				if (stack_b->head->value < stack_b->head->next->value)
				operation_sb(stack_b);
			}
		}
		i++;
	}
	i=0;
	while (stack_b->head!= NULL && i < 20)
	{
		if (stack_b->head!= NULL)
		{
			if (stack_b->head-> next != NULL) 
			{
				if (stack_b->head->value < stack_b->head->next->value)
					operation_sb(stack_b);
				else
					operation_pb (stack_a, stack_b);
			}
		}
		i++;
	}
	operation_pb (stack_a, stack_b);
	operation_rra(stack_a);	
}
*/

void	sort_stack2 (t_stack *stack_a, t_stack *stack_b)
{
	int	min_value;
	int	cost_to_rotate;
	int i;

	i = 0;
	while (stack_a->head->next != NULL)
	{
		min_value = find_min_value(stack_a);
		cost_to_rotate = get_cost_of_rotation(stack_a, min_value);
		if(cost_to_rotate == 1)
			operation_sa(stack_a);
		else if (cost_to_rotate > 1)
		{
			if (cost_to_rotate > stack_a->size / 2)
			{
				while ( i < stack_a->size - cost_to_rotate)
				{
					operation_rra(stack_a);
					i++;
				}
			}
			if (cost_to_rotate <= stack_a->size / 2)
			{
				while (i < cost_to_rotate)
				{
					operation_ra(stack_a);
					i++;
				}
			}
		}
		i = 0;
		operation_pb(stack_a, stack_b);
	}
	while (stack_b->size > 0)
		operation_pa(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1)
		ft_error(NULL, NULL);
	if (!check_input(argv, argc))
		ft_error(NULL, NULL);
	stack_a = NULL;
	stack_b = initialize_stack();
	if (!stack_b)
				ft_error(stack_a, stack_b);
	if (argc > 1)
		{
			stack_a = parse_arguments_for_stack_a(argc, argv);
			if (!stack_a)
				ft_error(stack_a, stack_b);
		}
	sort_stack2(stack_a, stack_b);
	/* test
	t_node *current = stack_a->head;
	printf ("stack_a:");
    while (current != NULL)
	{
        printf("%d ", current->value);
        current = current->next;
    }
	printf("\n");
	current = stack_b->head;
	printf ("stack_b:");
    while (current != NULL)
	{
        printf("%d ", current->value);
        current = current->next;
    }
*/
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
