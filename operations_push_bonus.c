/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkajanek <tkajanek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 17:09:38 by tkajanek          #+#    #+#             */
/*   Updated: 2023/04/02 18:18:54 by tkajanek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	push_bonus(t_stack *stack_src, t_stack *stack_dst)
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

void	operation_pb_bonus(t_stack *stack_a, t_stack *stack_b)
{
	push_bonus(stack_a, stack_b);
}

void	operation_pa_bonus(t_stack *stack_a, t_stack *stack_b)
{
	push_bonus(stack_b, stack_a);
}
