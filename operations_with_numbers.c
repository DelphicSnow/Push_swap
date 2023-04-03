/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_with_numbers.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkajanek <tkajanek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 15:32:43 by tkajanek          #+#    #+#             */
/*   Updated: 2023/04/01 16:48:08 by tkajanek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_index(t_stack *stack_a)
{
	int		tmp_value;
	int		size;
	t_node	*highest;
	t_node	*current;

	size = stack_a->size;
	current = stack_a->head;
	while (size)
	{
		tmp_value = INT_MIN;
		current = stack_a->head;
		while (current)
		{
			if (current->value == INT_MIN && current->index == 0)
				current->index = 1;
			if (current->value > tmp_value && current->index == 0)
			{
				tmp_value = current->value;
				highest = current;
			}
			current = current->next;
		}
		highest->index = size--;
	}
}

long long	ft_atoi(const char *nptr)
{
	int			minus_sign;
	long long	result;

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
	int	j;

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
