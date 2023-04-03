/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkajanek <tkajanek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 18:14:38 by tkajanek          #+#    #+#             */
/*   Updated: 2023/04/02 18:34:29 by tkajanek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

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

/*stack operations*/
void	operation_sa_bonus(t_stack *stack_a);
void	operation_sb_bonus(t_stack *stack_b);
void	operation_ss_bonus(t_stack *stack_a, t_stack *stack_b);
void	operation_pb_bonus(t_stack *stack_a, t_stack *stack_b);
void	operation_pa_bonus(t_stack *stack_a, t_stack *stack_b);
void	operation_ra_bonus(t_stack *stack_a);
void	operation_rb_bonus(t_stack *stack_b);
void	operation_rr_bonus(t_stack *stack_a, t_stack *stack_b);
void	operation_rra_bonus(t_stack *stack_a);
void	operation_rrb_bonus(t_stack *stack_b);
void	operation_rrr_bonus(t_stack *stack_a, t_stack *stack_b);

/*parsing a string as a input*/
t_stack	*parse_string(t_stack *stack_a, int *argc_ptr,char **argv);
char	**ft_split(char const *s, char c);

/*stack functions*/
t_node	*get_tail(t_stack	*stack);
t_node	*get_before_tail(t_stack	*stack);
t_stack *parse_arguments_for_stack_a(int argc, char **argv);
t_stack *initialize_stack(void);
t_node *create_node(t_stack *stack, int value);

/*error and free functions*/
void	free_stack(t_stack *stack);
void	ft_error(t_stack *stack_a, t_stack *stack_b);

/*operations with numbers*/
int			check_input(char **argv, int argc);
long long 	ft_atoi(const char *nptr);

/*utils*/
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*get_next_line(int fd);
int		ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s, int i);
char	*ft_strjoin(char *static_buff, char const *read_buffer);

#endif