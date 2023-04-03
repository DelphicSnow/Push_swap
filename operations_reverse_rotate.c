/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_reverse_rotate.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkajanek <tkajanek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 17:14:38 by tkajanek          #+#    #+#             */
/*   Updated: 2023/04/01 17:16:20 by tkajanek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack *stack)
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

void	operation_rra(t_stack *stack_a)
{
	reverse_rotate(stack_a);
	write (1, "rra\n", 4);
}

void	operation_rrb(t_stack *stack_b)
{
	reverse_rotate(stack_b);
	write (1, "rrb\n", 4);
}

void	operation_rrr(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write (1, "rrr\n", 4);
}
