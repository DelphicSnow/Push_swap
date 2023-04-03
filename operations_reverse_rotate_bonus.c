/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_reverse_rotate_bonus.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkajanek <tkajanek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 17:14:38 by tkajanek          #+#    #+#             */
/*   Updated: 2023/04/02 17:54:58 by tkajanek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	reverse_rotate_bonus(t_stack *stack)
{
	t_node	*tmp;
	t_node	*tail;
	t_node	*before_tail;

	tail = get_tail(stack);
	before_tail = get_before_tail(stack);
	tmp = stack->head;
	stack->head = tail;
	tail->next = tmp;
	before_tail->next = NULL;
}

void	operation_rra_bonus(t_stack *stack_a)
{
	reverse_rotate_bonus(stack_a);
}

void	operation_rrb_bonus(t_stack *stack_b)
{
	reverse_rotate_bonus(stack_b);
}

void	operation_rrr_bonus(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate_bonus(stack_a);
	reverse_rotate_bonus(stack_b);
}
