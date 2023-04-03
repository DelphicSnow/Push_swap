/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkajanek <tkajanek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 17:11:28 by tkajanek          #+#    #+#             */
/*   Updated: 2023/04/02 17:55:05 by tkajanek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	rotate_bonus(t_stack *stack)
{
	t_node	*tmp;
	t_node	*tail;

	tmp = stack->head;
	stack->head = stack->head->next;
	tail = get_tail(stack);
	tail->next = tmp;
	tmp ->next = NULL;
}

void	operation_ra_bonus(t_stack *stack_a)
{
	rotate_bonus(stack_a);
}

void	operation_rb_bonus(t_stack *stack_b)
{
	rotate_bonus(stack_b);
}

void	operation_rr_bonus(t_stack *stack_a, t_stack *stack_b)
{
	rotate_bonus(stack_a);
	rotate_bonus(stack_b);
}
