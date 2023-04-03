/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkajanek <tkajanek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 18:13:40 by tkajanek          #+#    #+#             */
/*   Updated: 2023/04/02 18:23:43 by tkajanek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int do_operation(t_stack *a, t_stack *b, char *operation)
{
	if (!ft_strncmp(operation, "sa\n", 3))
		return (operation_sa_bonus(a), 1);
	else if (!ft_strncmp(operation, "sb\n", 3))
		return (operation_sb_bonus(b), 1);
	else if (!ft_strncmp(operation, "ss\n", 3))
		return (operation_ss_bonus(a, b), 1);
	else if (!ft_strncmp(operation, "pa\n", 3))
		return (operation_pa_bonus(a, b), 1);
	else if (!ft_strncmp(operation, "pb\n", 3))
		return (operation_pb_bonus(a, b), 1);
	else if (!ft_strncmp(operation, "ra\n", 3))
		return (operation_ra_bonus(a), 1);
	else if (!ft_strncmp(operation, "rb\n", 3))
		return (operation_rb_bonus(b), 1);
	else if (!ft_strncmp(operation, "rr\n", 3))
		return (operation_rr_bonus(a, b), 1);
	else if (!ft_strncmp(operation, "rra\n", 4))
		return (operation_rra_bonus(a), 1);
	else if (!ft_strncmp(operation, "rrb\n", 4))
		return (operation_rrb_bonus(b), 1);
	else if (!ft_strncmp(operation, "rrr\n", 4))
		return (operation_rrr_bonus(a, b), 1);
	else
		return (0);
}

static void	read_sort_input(t_stack *stack_a, t_stack *stack_b)
{
	char	*buffer;

	buffer = get_next_line(STDIN_FILENO);
	while (buffer)
	{
		
		if (do_operation(stack_a, stack_b, buffer) == 0)
		{
			free(buffer);
			write(1,"Error\n", 6);
			ft_error(stack_a, stack_b);
		}
		free(buffer);
		buffer = get_next_line(STDIN_FILENO);
	}
}

static int	is_sorted_bonus(t_stack *stack)
{
	t_node	*current;

	current = stack->head;
	while (current->next != NULL)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	free_stack(stack);
	return(1);
}

static void	print_result(t_stack *a, int orig_size)
{
	if (is_sorted_bonus(a) && orig_size == a->size)
		write(1,"OK\n", 3);
	else
		write(1,"KO\n", 3);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		orig_size;

	if (argc == 1)
		return (0);
	stack_a = NULL;
	if (argc == 2)
		stack_a = parse_string(stack_a, &argc, argv);
	else if (argc > 2)
	{
		if (!check_input(argv, argc))
			ft_error(stack_a, NULL);
		stack_a = parse_arguments_for_stack_a(argc, argv);
		if (!stack_a)
			ft_error(stack_a, NULL);
	}
	stack_b = initialize_stack();
	if (!stack_b)
		ft_error(stack_a, stack_b);
	orig_size = stack_a->size;
	read_sort_input(stack_a, stack_b);
	print_result(stack_a, orig_size);
	free_stack(stack_a);
	free_stack(stack_b);
}
