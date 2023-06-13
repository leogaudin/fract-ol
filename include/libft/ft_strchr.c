/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:56:03 by lgaudin           #+#    #+#             */
/*   Updated: 2023/04/15 18:01:30 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

// char	*ft_strchr(const char *s, int c)
// {
// 	int	index;

// 	index = 0;
// 	while (s[index])
// 	{
// 		if (s[index] == c)
// 			return ((char *)&s[index]);
// 		index++;
// 	}
// 	if (c == '\0')
// 		return ((char *)&s[index]);
// 	return (0);
// }

char	*ft_strchr(const char *s, int c)
{
	size_t			index;
	unsigned char	*s_pointer;

	index = 0;
	s_pointer = (unsigned char *)s;
	while (s_pointer[index])
	{
		if (s_pointer[index] == (unsigned char)c)
			return ((char *)&s_pointer[index]);
		index++;
	}
	if (c == '\0' || c == 1024)
		return ((char *)&s_pointer[index]);
	return (0);
}

// int	main(void)
// {
// 	char	c;
// 	char	*s;

// 	c = 'u';
// 	s = "euuuuuh ?";
// 	printf("strchr returned %s\n", strchr("teste", 1024));
// 	printf("ft_strchr returned %s\n", ft_strchr("teste", 1024));
// 	printf("Théo Babac returned %s\n", s);
// 	return (0);
// }
