/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkajanek <tkajanek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:07:34 by tkajanek          #+#    #+#             */
/*   Updated: 2023/03/26 20:32:40 by tkajanek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void print_stacks(t_stack *stack_a, t_stack *stack_b)
{
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
}*/

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1)
		return(0);
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
	assign_index(stack_a);
	sort_stack (stack_a, stack_b, argc);
	/*sort_3(stack_a, stack_b);*/
	/*selection_sort(stack_a, stack_b);*/
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
