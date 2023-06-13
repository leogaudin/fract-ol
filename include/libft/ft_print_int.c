/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 12:54:20 by lgaudin           #+#    #+#             */
/*   Updated: 2023/06/09 13:46:43 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_abs(long i)
{
	if (i < 0)
		return (-i);
	return (i);
}

static int	ft_print_sign(int *n, t_flags *flags)
{
	int	count;

	count = 0;
	if (flags->plus && *n >= 0)
	{
		ft_putchar_fd('+', 1);
		count++;
	}
	if (*n < 0)
	{
		ft_putchar_fd('-', 1);
		*n *= -1;
		count++;
	}
	if (flags->space && *n >= 0)
	{
		ft_putchar_fd(' ', 1);
		count++;
	}
	return (count);
}

int	ft_print_int_with_width(int n, t_flags *flags, char padding)
{
	int	count;

	count = 0;
	if (flags->minus)
	{
		count += ft_print_sign(&n, flags);
		ft_putnbr_fd(n, 1);
		count += ft_print_padding(flags->width, ft_intlen(n), padding);
	}
	else
	{
		count += ft_print_padding(flags->width, ft_intlen(n), padding);
		count += ft_print_sign(&n, flags);
		ft_putnbr_fd(n, 1);
	}
	return (count);
}

int	ft_print_int_without_width(int n, t_flags *flags)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", 1);
		return (1);
	}
	count += ft_print_sign(&n, flags);
	ft_putnbr_fd(n, 1);
	return (count);
}

int	ft_print_int(int n, t_flags *flags)
{
	int		count;
	char	padding;

	count = 0;
	if (flags->width)
	{
		if ((flags->plus || flags->space) && n >= 0)
			flags->width--;
		if (flags->zero)
			padding = '0';
		else
			padding = ' ';
		count += ft_print_int_with_width(n, flags, padding);
	}
	else
		count += ft_print_int_without_width(n, flags);
	count += ft_intlen(ft_abs(n));
	return (count);
}
