/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortings_algos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkajanek <tkajanek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 18:25:04 by tkajanek          #+#    #+#             */
/*   Updated: 2023/03/26 20:29:23 by tkajanek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    radix_sort(t_stack *stack_a, t_stack *stack_b)
{
    int size = stack_a->size;
    t_radix_data  data;
    int i;
    int j;

    data.max_bits = 0;
    while ((stack_a->size >> data.max_bits) != 0)
        data.max_bits++;
    i = 0;
    while (i < data.max_bits)
    {
        j = 0;
        while (j < size)
        {
            data.head_number = stack_a->head->index;
            if (((data.head_number >> i) & 1) == 1)
                operation_ra(stack_a); 
            else
                operation_pb(stack_a, stack_b);
            j++;
        }
        while (stack_b->size)
            operation_pa(stack_a, stack_b);
        i++;
    }
}

void	sort_3(t_stack *stack, int size) //zjistit jestli funguje po tom co se zmeni size
{
	if (stack->head->index == size)
		operation_ra(stack);
	else if (stack->head->next->index == size)
		operation_rra(stack);
	if (stack->head->index > stack->head->next->index)
		operation_sa(stack);
}

void    sort_stack (t_stack *stack_a, t_stack *stack_b, int argc)
{
    if (argc == 4)
        sort_3(stack_a, stack_a->size);
    else if (argc == 5 || argc == 6)
        selection_sort(stack_a, stack_b);
    else
        radix_sort(stack_a, stack_b);
}
