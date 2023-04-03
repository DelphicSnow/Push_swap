/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkajanek <tkajanek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 20:39:12 by tkajanek          #+#    #+#             */
/*   Updated: 2023/04/02 18:53:53 by tkajanek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char	*csrc;
	char		*cdest;

	if (dest == NULL && src == NULL)
		return (NULL);
	csrc = (char *)src;
	cdest = (char *)dest;
	while (n > 0)
	{
		*cdest++ = *csrc++;
		n--;
	}
	return (dest);
}

static void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*arr;
	size_t	test;
	size_t	i;

	if (nmemb == 0 || size == 0)
	{
		arr = malloc(0);
		return (arr);
	}
	test = nmemb * size;
	if (test / nmemb != size)
		return (NULL);
	arr = malloc(nmemb * size);
	if (!arr)
		return (NULL);
	i = 0;
	while (i < test)
	{
		((char *)arr)[i] = '\0';
		i++;
	}
	return (arr);
}

static char	**fucknorminette(char const *s, char **arr, char c, int j)
{
	int	len;
	int	i;

	i = 0;
	while (s[j])
	{
		while (s[j] == c)
			j++;
		if (s[j] != 0)
		{
			len = 0;
			while (s[j + len] != c && s[j + len] != 0)
				len++;
			arr[i] = ft_calloc(sizeof(char), len +1);
			ft_memcpy(arr[i], &s[j], len);
			i++;
			j = j + len;
		}
	}
	arr[i] = 0;
	return (arr);
}

static int	word_counter(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s != 0)
	{
		while (*s == c)
			s++;
		while (*s != c && *s != 0)
		{
			s++;
			if (*s == '\0' || *s == c)
				count++;
		}
	}
	count ++;
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		j;

	if (s == 0)
		return (0);
	j = 0;
	arr = (char **)malloc(sizeof(char *) * word_counter(s, c));
	if (!arr)
		return (0);
	fucknorminette(s, arr, c, j);
	return (arr);
}
