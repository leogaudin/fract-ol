/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 13:27:37 by lgaudin           #+#    #+#             */
/*   Updated: 2023/06/17 18:35:55 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

/**
 * @brief    Puts the provided color to the pixel at the provided coordinates.
 *
 * @param    fractal
 * @param    x         The graphic x coordinate
 * @param    y         The graphic y coordinate
 * @param    color     The color to put to the pixel.
 */
void	put_color_to_pixel(t_fractal *fractal, int x, int y, int color)
{
	int	*buffer;

	buffer = fractal->pointer_to_image;
	buffer[(y * fractal->size_line / 4) + x] = color;
}

/**
 * @brief    Exits the program.
 *
 * @param    fractal
 */
int	exit_fractal(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->image);
	mlx_destroy_window(fractal->mlx, fractal->window);
	free(fractal->mlx);
	free(fractal);
	exit(1);
	return (0);
}

/**
 * @brief    Generates a random double between -1.5 and 1.5.
 *
 * @return   double    The random double.
 */
double	generate_random_c(void)
{
	return (((double)rand() / RAND_MAX) * 3.0 - 1.5);
}

/**
 * @brief    Increases or decreases the number of iterations.
 * The lower the number of iterations is, the faster the fractal is generated.
 *
 * @param    fractal
 * @param    key_code
 */
void	change_iterations(t_fractal *fractal, int key_code)
{
	if (key_code == M)
	{
		if (fractal->max_iterations > 42)
			fractal->max_iterations -= 42;
	}
	else if (key_code == P)
	{
		if (fractal->max_iterations < 4200)
			fractal->max_iterations += 42;
	}
}
