/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 12:54:07 by lgaudin           #+#    #+#             */
/*   Updated: 2023/06/09 13:46:43 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_pointer(unsigned long long p, t_flags *flags)
{
	int	count;

	count = 0;
	flags->hash = 0;
	count += ft_print_string("0x");
	count += ft_print_hexa(p, 'x', flags);
	return (count);
}
