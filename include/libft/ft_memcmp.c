/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:34:23 by lgaudin           #+#    #+#             */
/*   Updated: 2023/04/11 16:39:01 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_pointer;
	unsigned char	*s2_pointer;

	i = 0;
	s1_pointer = (unsigned char *)s1;
	s2_pointer = (unsigned char *)s2;
	while (i < n)
	{
		if (s1_pointer[i] != s2_pointer[i])
			return (s1_pointer[i] - s2_pointer[i]);
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	char	*s1;
// 	char	*s2;

// 	s1 = "\0euuh ?";
// 	s2 = "\0euuh \0?";
// 	printf("memcmp returned %d\n", memcmp(s1, s2, 10));
// 	printf("ft_memcmp returned %d\n", ft_memcmp(s1, s2, 10));
// 	return (0);
// }
