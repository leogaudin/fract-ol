/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 13:27:23 by lgaudin           #+#    #+#             */
/*   Updated: 2023/06/16 13:35:37 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	calculate_mandelbrot(t_fractal *fractal)
{
	int		x;
	int		y;
	int		i;
	double	x_temp;

	x = fractal->translated_x;
	y = fractal->translated_y;
	i = 0;
	fractal->zx = 0.0;
	fractal->zy = 0.0;
	fractal->cx = x / fractal->zoom + fractal->offset_x;
	fractal->cy = y / fractal->zoom + fractal->offset_y;
	while (fractal->zx * fractal->zx + fractal->zy * fractal->zy < 7.
		&& ++i < MAX_ITERATIONS)
	{
		x_temp = fractal->zx * fractal->zx - fractal->zy * fractal->zy
			+ fractal->cx;
		fractal->zy = 2. * fractal->zx * fractal->zy + fractal->cy;
		fractal->zx = x_temp;
	}
	if (i == MAX_ITERATIONS)
		put_color_to_pixel(fractal->mlx, fractal->x, fractal->y, 0x000);
	else
		put_color_to_pixel(fractal->mlx, fractal->x, fractal->y, (i
				* 0xF3420B));
}
