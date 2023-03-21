/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkajanek <tkajanek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 19:21:03 by tkajanek          #+#    #+#             */
/*   Updated: 2023/03/21 16:20:31 by tkajanek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	int	tmp;

	tmp = stack->head->value;
	stack->head->value = stack->head->next->value;
	stack->head->next->value = tmp;
}

void	operation_sa (t_stack *stack_a)
{
	swap(stack_a);
	write (1, "sa\n", 3);
}

void	operation_sb (t_stack *stack_b)
{
	swap(stack_b);
	write (1, "sb\n", 3);
}

void	operation_ss (t_stack *stack_a, t_stack *stack_b)

{
	swap(stack_a);
	swap(stack_b);
	write (1, "ss\n", 3);
}

void	push(t_stack *stack_src, t_stack *stack_dst)
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

void	operation_pb (t_stack *stack_a, t_stack *stack_b)
{
	push(stack_a, stack_b);
	write (1, "pb\n", 3);
}

void	operation_pa (t_stack *stack_a, t_stack *stack_b)
{
	push(stack_b, stack_a);
	write (1, "pa\n", 3);
}

t_node	* get_tail (t_stack	*stack)
{
	t_node	*current;

	current = stack->head;
	if (stack->head == NULL)
		return (NULL);
	while (current->next)
	{
		current = current->next;
	}
	return (current);
}

t_node	* get_before_tail (t_stack	*stack)
{
	t_node	*current;

	current = stack->head;
	if (stack->head == NULL)
		return (NULL);
	if (stack->head->next == NULL)
		return (NULL);
	while (current->next->next)
	{
		current = current->next;
	}
	return (current);
}

void	rotate(t_stack *stack)
{
	t_node	*tmp;
	t_node	*tail;

	tmp = stack->head;
	stack->head = stack->head->next;
	tail = get_tail(stack);
	tail->next = tmp;
	tmp ->next = NULL;
}

void	operation_ra (t_stack *stack_a)
{
	rotate(stack_a);
	write (1, "ra\n", 3);
}

void	operation_rb (t_stack *stack_b)
{
	rotate(stack_b);
	write (1, "rb\n", 3);
}

void	operation_rr (t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write (1, "rr\n", 3);
}

void	reverse_rotate(t_stack *stack)
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

void operation_rra(t_stack *stack_a)
{
	reverse_rotate(stack_a);
	write (1, "rra\n", 4);
}

void operation_rrb(t_stack *stack_b)
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