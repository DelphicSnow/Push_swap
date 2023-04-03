/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkajanek <tkajanek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:31:45 by tkajanek          #+#    #+#             */
/*   Updated: 2023/04/02 18:42:07 by tkajanek         ###   ########.fr       */
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
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	int		size;
	t_node	*head;
}	t_stack;

typedef struct s_data
{
	int	size;
	int	max_bits;
	int	head_number;
}	t_radix_data;

/*operations with numbers*/
int			check_input(char **argv, int argc);
void		assign_index(t_stack *stack_a);
long long	ft_atoi(const char *nptr);

/*stack operations*/
void		operation_sa(t_stack *stack_a);
void		operation_sb(t_stack *stack_b);
void		operation_ss(t_stack *stack_a, t_stack *stack_b);
void		operation_pb(t_stack *stack_a, t_stack *stack_b);
void		operation_pa(t_stack *stack_a, t_stack *stack_b);
void		operation_ra(t_stack *stack_a);
void		operation_rb(t_stack *stack_b);
void		operation_rr(t_stack *stack_a, t_stack *stack_b);
void		operation_rra(t_stack *stack_a);
void		operation_rrb(t_stack *stack_b);
void		operation_rrr(t_stack *stack_a, t_stack *stack_b);

/*parsing a string as a input*/
t_stack		*parse_string(t_stack *stack_a, int *argc_ptr, char **argv);
char		**ft_split(char const *s, char c);

/*stack functions*/
t_node		*get_tail(t_stack *stack);
t_node		*get_before_tail(t_stack *stack);
t_stack		*parse_arguments_for_stack_a(int argc, char **argv);
t_stack		*initialize_stack(void);
t_node		*create_node(t_stack *stack, int value);

/*error and free functions*/
void		free_stack(t_stack *stack);
void		ft_error(t_stack *stack_a, t_stack *stack_b);

/*sorting algos*/
void		sort_stack(t_stack *stack_a, t_stack *stack_b, int argc);
void		selection_sort(t_stack *stack_a, t_stack *stack_b);
void		sort_3(t_stack *stack, int size);
void		radix_sort(t_stack *stack_a, t_stack *stack_b);

#endif