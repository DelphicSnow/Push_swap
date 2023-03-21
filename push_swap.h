/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkajanek <tkajanek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:31:45 by tkajanek          #+#    #+#             */
/*   Updated: 2023/03/21 16:20:36 by tkajanek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_node
{
	int				value;
	//int				rotate_cost;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	int		size;
	t_node	*head;
}	t_stack;

t_stack *parse_arguments_for_stack_a(int argc, char **argv);
t_node *create_node(t_stack *stack, int value);
long long int	ft_atoi(const char *nptr);
void	swap(t_stack *stack);
void	operation_sa (t_stack *stack_a);
void	operation_sb (t_stack *stack_b);
void	operation_ss (t_stack *stack_a, t_stack *stack_b);
void	push(t_stack *stack_src, t_stack *stack_dst);
void	operation_pb (t_stack *stack_a, t_stack *stack_b);
void	operation_pa (t_stack *stack_a, t_stack *stack_b);
t_node	*get_tail (t_stack	*stack);
t_node	*get_before_tail (t_stack	*stack);
void	rotate(t_stack *stack);
void	operation_ra (t_stack *stack_a);
void	operation_rb (t_stack *stack_b);
void	operation_rr (t_stack *stack_a, t_stack *stack_b);
void	reverse_rotate(t_stack *stack);
void	operation_rra(t_stack *stack_a);
void	operation_rrb(t_stack *stack_b);
void	operation_rrr(t_stack *stack_a, t_stack *stack_b);
//void	sort_stack (t_stack *stack_a, t_stack *stack_b);
void	sort_stack2 (t_stack *stack_a, t_stack *stack_b);
t_stack *initialize_stack(void);
int	get_cost_of_rotation(t_stack *stack, int wanted_value);
int	find_min_value(t_stack *stack);
void	free_stack(t_stack *stack);
void	ft_error(t_stack *stack_a, t_stack *stack_b);
int	check_input(char **argv, int argc);

#endif