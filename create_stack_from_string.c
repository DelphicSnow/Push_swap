/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack_from_string.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkajanek <tkajanek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 12:32:22 by tkajanek          #+#    #+#             */
/*   Updated: 2023/04/01 17:52:09 by tkajanek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_pointers(char **arr, int argc)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static char	**copy_argv_plus_name(char **arr_src, int argc)
{
	char	*arg;
	int		i;
	char	**arr_dst;

	arr_dst = (char **)malloc(sizeof(char *) * argc);
	arg = (char *)malloc(sizeof(char) * 2);
	if (!arg)
		return (NULL);
	arg[0] = '!';
	arg[1] = '\0';
	arr_dst[0] = arg;
	i = 0;
	while (i < argc - 1)
	{
		arr_dst[i + 1] = arr_src[i];
		i++;
	}
	free(arr_src);
	return (arr_dst);
}

t_stack	*parse_string(t_stack *stack_a, int *argc_ptr, char **argv)
{
	char	**argv_after_split;
	char	**argv_after_split_plus_name;
	int		argc;

	argc = 1;
	argv_after_split = ft_split(argv[1], ' ');
	while (argv_after_split[argc -1] != 0)
		argc ++;
	*argc_ptr = argc;
	argv_after_split_plus_name = copy_argv_plus_name(argv_after_split, argc);
	if (!check_input(argv_after_split_plus_name, argc))
	{
		free_pointers (argv_after_split_plus_name, argc);
		ft_error(stack_a, NULL);
	}
	stack_a = parse_arguments_for_stack_a(argc, argv_after_split_plus_name);
	free_pointers (argv_after_split_plus_name, argc);
	return (stack_a);
}
