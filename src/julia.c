/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 13:55:52 by lgaudin           #+#    #+#             */
/*   Updated: 2023/06/17 14:08:43 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	calculate_julia(t_fractal *fractal)
{
	int		i;
	double	tmp;

	fractal->name = "julia";
	i = 0;
	fractal->cx = -0.808;
	fractal->cy = 0.168;
	fractal->zx = fractal->x / fractal->zoom + fractal->offset_x;
	fractal->zy = fractal->y / fractal->zoom + fractal->offset_y;
	while (fractal->zx * fractal->zx + fractal->zy * fractal->zy < 4
		&& i < MAX_ITERATIONS)
	{
		tmp = fractal->zx;
		fractal->zx = fractal->zx * fractal->zx - fractal->zy
			* fractal->zy + fractal->cx;
		fractal->zy = 2 * fractal->zy * tmp + fractal->cy;
		i++;
	}
	if (i == MAX_ITERATIONS)
		put_color_to_pixel(fractal, fractal->x, fractal->y, 0x000000);
	else
		put_color_to_pixel(fractal, fractal->x, fractal->y,
			 (fractal->color * (i % 255)));
}
