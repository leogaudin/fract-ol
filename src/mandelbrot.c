/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 13:27:23 by lgaudin           #+#    #+#             */
/*   Updated: 2023/06/17 20:20:58 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

/**
 * @brief    Calculates the Mandelbrot fractal for one pixel.
 *
 * The z variables are set to 0, the beginning of the suite.
 *
 * The c constants are set to the coordinates of the pixel.
 *
 * For performance reasons, we use the (x * x) calculation instead of the
 * pow(x, 2) function.
 *
 * The exit conditions of the loop are the following:
 * - The absolute value of z is greater than the system's max values, then
 *   we can assure that the suite will diverge to infinity.
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
	int		i;
	double	x_temp;

	fractal->name = "mandel";
	i = 0;
	fractal->zx = 0.0;
	fractal->zy = 0.0;
	fractal->cx = (fractal->x / fractal->zoom) + fractal->offset_x;
	fractal->cy = (fractal->y / fractal->zoom) + fractal->offset_y;
	while (++i < fractal->max_iterations)
	{
		x_temp = fractal->zx * fractal->zx - fractal->zy * fractal->zy
			+ fractal->cx;
		fractal->zy = 2. * fractal->zx * fractal->zy + fractal->cy;
		fractal->zx = x_temp;
		if (fractal->zx * fractal->zx + fractal->zy
			* fractal->zy >= __DBL_MAX__)
			break ;
	}
	if (i == fractal->max_iterations)
		put_color_to_pixel(fractal, fractal->x, fractal->y, 0x000000);
	else
		put_color_to_pixel(fractal, fractal->x, fractal->y, (fractal->color
				* i));
}
