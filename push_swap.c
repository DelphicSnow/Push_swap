/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkajanek <tkajanek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:07:34 by tkajanek          #+#    #+#             */
/*   Updated: 2023/03/17 19:48:16 by tkajanek         ###   ########.fr       */
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
	char c;
	int	j; //test

	i = 0;
	j = 0; //test
	while (stack_a->head->next != NULL && j < 2)
	{
		write(1, "stack_a size:", 13);
		c = stack_a->size + 48;
		write(1, &c, 1);
		write(1, "\n", 1);
		write(1, "stack_b size:", 13);
		c = stack_b->size + 48;
		write(1, &c, 1);
		write(1, "\n", 1);

		min_value = find_min_value(stack_a);
		write(1, "min value:", 10);
		c = min_value + 48;
		write(1, &c, 1);
		write(1, "\n", 1);

		cost_to_rotate = get_cost_of_rotation(stack_a, min_value);
		//kdyz nula, tak nic
		write(1, "cost:", 5);
		c = cost_to_rotate + 48;
		write(1, &c, 1);
		write(1, "\n", 1);

		if(cost_to_rotate == 1)
			operation_sa(stack_a);
		else if (cost_to_rotate > 1)
		{
			if (cost_to_rotate >= stack_a->size / 2)
			{
				while ( i < stack_a->size - cost_to_rotate)
				{
					operation_ra(stack_a);
					i++;
				}
			}
			if (cost_to_rotate < stack_a->size / 2)
			{
				while (i < cost_to_rotate)
				{
					operation_rra(stack_a);
					i++;
				}
			}
		}
		i = 0;
		operation_pa(stack_a, stack_b);
		//vypise oba stacky
		write (1, "loop\n", 6);
		t_node *current = stack_a->head;
		write(1, "stack_a:", 8);
		while (current != NULL)
		{
			char buffer[12]; // assuming 32-bit integers
			int len = snprintf(buffer, sizeof(buffer), "%d ", current->value);
			write(1, buffer, len);
			current = current->next;
		}
		write(1, "\n", 1);
		current = stack_b->head;
		write(1, "stack_b:", 8);
		while (current != NULL)
		{
			char buffer[12]; // assuming 32-bit integers
			int len = snprintf(buffer, sizeof(buffer), "%d ", current->value);
			write(1, buffer, len);
			current = current->next;
		}
		write(1, "\n\n", 2);
	}
	while (stack_b->size > 1)
		operation_pb(stack_a, stack_b);
}

int	ft_atoi(const char *nptr)
{
	int	minus_sign;
	int	result;

	result = 0;
	minus_sign = 1;
	
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			minus_sign *= -1;
		nptr ++;
	}
	while (*nptr != '\0' && *nptr >= '0' && *nptr <= '9')
	{
		result = result * 10 + (*nptr - 48);
		nptr ++;
	}
	return (result * minus_sign);
}





int	main(int argc, char **argv)
//int	main(void)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	//vlozit za pocatecni podminky
	stack_b = initialize_stack(stack_b);
	if (argc > 1)
		{
			stack_a = parse_arguments(argc, argv);
			//if (!stack)
		}
	sort_stack2(stack_a, stack_b);
	//test
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

//	free_stack;
	return (0);
}