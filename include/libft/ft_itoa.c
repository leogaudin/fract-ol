/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:30:31 by lgaudin           #+#    #+#             */
/*   Updated: 2023/04/13 11:40:56 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static int	get_digits(long int n)
{
	int	count;

	count = 1;
	while (n >= 10)
	{
		n /= 10;
		count++;
	}
	return (count);
}

// static void	ft_rev_tab(char *tab, int size)
// {
// 	int		i;
// 	char	*array;

// 	i = 0;
// 	array = malloc((size + 1) * sizeof(char));
// 	if (!array)
// 		return ;
// 	while (i < size)
// 	{
// 		array[i] = *tab;
// 		if (i != size - 1)
// 			tab++;
// 		i++;
// 	}
// 	i--;
// 	tab -= (size - 1);
// 	while (i >= 0)
// 	{
// 		*tab++ = array[i];
// 		i--;
// 	}
// }

char	*ft_itoa(int n)
{
	int			digit_count;
	char		*result;
	long int	n_copy;

	n_copy = n;
	if (n_copy < 0)
		n_copy *= -1;
	digit_count = get_digits(n_copy);
	if (n < 0)
		digit_count++;
	result = malloc((digit_count + 1) * sizeof(char));
	if (!result)
		return (0);
	result[digit_count--] = '\0';
	while (digit_count >= 0)
	{
		result[digit_count--] = (n_copy % 10) + '0';
		n_copy /= 10;
	}
	if (n < 0)
		result[0] = '-';
	return (result);
}

// int	main(void)
// {
// 	printf("%s\n", ft_itoa(-2147483648));
// 	return (0);
// }
