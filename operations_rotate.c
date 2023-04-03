/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkajanek <tkajanek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 17:11:28 by tkajanek          #+#    #+#             */
/*   Updated: 2023/04/01 17:16:40 by tkajanek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack *stack)
{
	t_node	*tmp;
	t_node	*tail;

	tmp = stack->head;
	stack->head = stack->head->next;
	tail = get_tail(stack);
	tail->next = tmp;
	tmp ->next = NULL;
}

void	operation_ra(t_stack *stack_a)
{
	rotate(stack_a);
	write (1, "ra\n", 3);
}

void	operation_rb(t_stack *stack_b)
{
	rotate(stack_b);
	write (1, "rb\n", 3);
}

void	operation_rr(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write (1, "rr\n", 3);
}
