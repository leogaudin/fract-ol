/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:30:01 by lgaudin           #+#    #+#             */
/*   Updated: 2023/04/19 16:02:03 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "libft.h"

static int	strings_count(char const *str, char c)
{
	int	strings_count;

	strings_count = 0;
	while (*str)
	{
		if (*str != c)
		{
			strings_count++;
			while (*str && *str != c)
				str++;
		}
		else
			str++;
	}
	return (strings_count);
}

static int	string_length(char const *s, char c, int i)
{
	int	length;

	length = 0;
	while (s[i] != c && s[i])
	{
		length++;
		i++;
	}
	return (length);
}

static void	free_all(char **result, int index)
{
	while (index-- > 0)
		free(result[index]);
	free(result);
}

char	**ft_split(char const *s, char c)
{
	int		index;
	char	**result;
	int		result_index;

	index = 0;
	result_index = -1;
	result = malloc((strings_count(s, c) + 1) * sizeof(char *));
	if (!result)
		return (0);
	while (++result_index < strings_count(s, c))
	{
		while (s[index] == c)
			index++;
		result[result_index] = ft_substr(s, index, string_length(s, c, index));
		if (!(result[result_index]))
		{
			free_all(result, result_index);
			return (0);
		}
		index += string_length(s, c, index);
	}
	result[result_index] = 0;
	return (result);
}
