/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkajanek <tkajanek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 15:32:43 by tkajanek          #+#    #+#             */
/*   Updated: 2023/03/21 16:20:38 by tkajanek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long int	ft_atoi(const char *nptr)
{
	int		minus_sign;
	long long int	result;

	result = 0;
	minus_sign = 1;
	
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			minus_sign *= -1;
		nptr ++;
	}
	while (*nptr != '\0' && *nptr >= '0' && *nptr <= '9')
	{
		result = result * 10 + (*nptr - 48);
		nptr ++;
	}
	if (*nptr != '\0' && !(*nptr >= '0' && *nptr <= '9'))
		return (0);
	return (result * minus_sign);
}

static void	free_nodes(t_node *head)
{
    t_node *current;
    t_node *next;

	current = head;
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
}

void	free_stack(t_stack *stack)
{
	if (stack != NULL)
	{
		if (stack->head != NULL)
			free_nodes(stack->head);
		free(stack);
	}
}

void	ft_error(t_stack *stack_a, t_stack *stack_b)
{
	free_stack(stack_a);
	free_stack(stack_b);
	write(2, "Error\n", 6);
	exit (1);
}

static int	is_arg_nmbr(char *argv)
{
	long long int	i;

	i = 0;
	while (argv[i] != '\0')
		i ++;
	if (*argv == '0' && i == 1)
		return (1);
	i = ft_atoi(argv);
	if (i < INT_MIN || i > INT_MAX)
		return (0);
	return ((int)i);
}	

static int	is_duplicate(char **argv, int argc)
{
	int	value;
	int	i;
	int j;

	value = 0;
	i = 1;
	j = 1;
	while (i < argc - 1)
	{
		value = (int)ft_atoi(argv[i]);
		j = 1;
		while (i + j < argc)
		{
			if (value == (int)ft_atoi(argv[i + j]))
				return (1);
			j++;
		}
		i ++;
	}
	return (0);
}

int	check_input(char **argv, int argc)
{
	int	i;
	char	c;

	i = 1;
	while (i < argc)
	{
		if (!is_arg_nmbr(argv[i]))
			return (0);
		i++;
	}
	if (is_duplicate(argv, argc))
		return (0);
	return (1);
}