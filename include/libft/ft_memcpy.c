/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 18:59:19 by lgaudin           #+#    #+#             */
/*   Updated: 2023/04/12 19:49:08 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			count;
	unsigned char	*dest_copy;
	unsigned char	*src_copy;

	if (!dest && !src)
		return (0);
	count = 0;
	dest_copy = (unsigned char *)dest;
	src_copy = (unsigned char *)src;
	while (count < n)
	{
		dest_copy[count] = (unsigned char)src_copy[count];
		count++;
	}
	return (dest);
}
