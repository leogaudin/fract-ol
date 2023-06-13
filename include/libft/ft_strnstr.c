/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:12:48 by lgaudin           #+#    #+#             */
/*   Updated: 2023/04/12 21:17:49 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int	i;
	int	j;

	if (little[0] == '\0' || (len == 0 && !big))
		return ((char *)big);
	i = 0;
	while (big[i] != '\0' && (size_t)i < len)
	{
		j = 0;
		while (little[j] != '\0' && (size_t)i + j < len)
		{
			if (big[i + j] == little[j])
			{
				j++;
			}
			else
				break ;
		}
		if (little[j] == '\0')
		{
			return ((char *)big + i);
		}
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	char	first[] = "Bonjour";
// 	char	second[] = "jour";
// 	int		limit = 10;
// 	printf("strstr returned %s\n", strnstr(first, second, limit));
// 	printf("ft_strstr returned %s\n", ft_strnstr(first, second, limit));
// 	return (0);
// }
