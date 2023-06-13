/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 19:08:04 by lgaudin           #+#    #+#             */
/*   Updated: 2023/04/12 21:15:21 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*src_pointer;
	unsigned char	*dest_pointer;

	if (src == NULL && dest == NULL)
		return (0);
	i = 0;
	src_pointer = (unsigned char *)src;
	dest_pointer = (unsigned char *)dest;
	if (dest_pointer > src_pointer)
		while (n-- != 0)
			dest_pointer[n] = src_pointer[n];
	else
	{
		while (i < n)
		{
			dest_pointer[i] = src_pointer[i];
			i++;
		}
	}
	return (dest);
}

// int	main(void)
// {
// 	char	str[] = "Start stop";

// 	printf("The string: %s\n", str);
// 	ft_memmove(str, str + 2, 3 * sizeof(char));
// 	printf("New string: %s\n", str);

// 	return (0);
// }
