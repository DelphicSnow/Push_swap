/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkajanek <tkajanek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 17:08:48 by tkajanek          #+#    #+#             */
/*   Updated: 2023/04/01 17:16:45 by tkajanek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack *stack)
{
	int	tmp;

	tmp = stack->head->value;
	stack->head->value = stack->head->next->value;
	stack->head->next->value = tmp;
	tmp = stack->head->index;
	stack->head->index = stack->head->next->index;
	stack->head->next->index = tmp;
}

void	operation_sa(t_stack *stack_a)
{
	swap(stack_a);
	write (1, "sa\n", 3);
}

void	operation_sb(t_stack *stack_b)
{
	swap(stack_b);
	write (1, "sb\n", 3);
}

void	operation_ss(t_stack *stack_a, t_stack *stack_b)

{
	swap(stack_a);
	swap(stack_b);
	write (1, "ss\n", 3);
}
