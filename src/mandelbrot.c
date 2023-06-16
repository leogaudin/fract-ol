/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 13:27:23 by lgaudin           #+#    #+#             */
/*   Updated: 2023/06/16 13:51:32 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

/**
 * @brief    Calculates the Mandelbrot fractal for one pixel.
 *
 * First, we translate the coordinates of the pixel to the center of the
 * window, because the Mandelbrot fractal's origin is the center not the
 * top left corner of the window.
 *
 * The z variables are set to 0, the beginning of the suite.
 *
 * The c constants are set to the coordinates of the pixel.
 *
 * For performance reasons, we use the (x * x) calculation instead of the
 * pow(x, 2) function.
 *
 * The exit conditions of the loop are the following:
 * - The absolute value of z is greater than 7, then we can assure
 *   that the suite will diverge to infinity.
 * - The number of iterations is too high, then we can assure that
 *   the suite will stay stuck in an infinite loop.
 *
 * If the the suite diverges, we color it and multiply the color by the
 * number of iterations to make the mathematical depths more clear to the
 * eye.
 *
 * @param    fractal
 */
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
	fractal->cx = (x / fractal->zoom) + fractal->offset_x;
	fractal->cy = (y / fractal->zoom) + fractal->offset_y;
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
