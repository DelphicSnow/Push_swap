/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkajanek <tkajanek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 17:08:48 by tkajanek          #+#    #+#             */
/*   Updated: 2023/04/02 17:55:08 by tkajanek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	swap_bonus(t_stack *stack)
{
	int	tmp;

	tmp = stack->head->value;
	stack->head->value = stack->head->next->value;
	stack->head->next->value = tmp;
	tmp = stack->head->index;
	stack->head->index = stack->head->next->index;
	stack->head->next->index = tmp;
}

void	operation_sa_bonus(t_stack *stack_a)
{
	swap_bonus(stack_a);
}

void	operation_sb_bonus(t_stack *stack_b)
{
	swap_bonus(stack_b);
}

void	operation_ss_bonus(t_stack *stack_a, t_stack *stack_b)

{
	swap_bonus(stack_a);
	swap_bonus(stack_b);
}
