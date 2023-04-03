/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkajanek <tkajanek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 17:09:38 by tkajanek          #+#    #+#             */
/*   Updated: 2023/04/01 17:15:51 by tkajanek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack *stack_src, t_stack *stack_dst)
{
	t_node	*tmp;

	if (stack_src == NULL)
		return ;
	tmp = stack_src->head->next;
	stack_src->head->next = stack_dst->head;
	stack_dst->head = stack_src->head;
	stack_src->head = tmp;
	stack_src->size -= 1;
	stack_dst->size += 1;
}

void	operation_pb(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_a, stack_b);
	write (1, "pb\n", 3);
}

void	operation_pa(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_b, stack_a);
	write (1, "pa\n", 3);
}
