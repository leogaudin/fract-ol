/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 22:55:04 by lgaudin           #+#    #+#             */
/*   Updated: 2023/06/17 14:08:21 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

/**
 * @brief    Iterates through the pixels of the window and calls the
 * appropriate function to draw the fractal.
 *
 * @param    fractal   The fractal structure.
 * @param    query     The name of the fractal to draw.
 */
int	draw_fractal(t_fractal *fractal, char *query)
{
	fractal->x = 0;
	fractal->y = 0;
	while (fractal->x < SIZE)
	{
		while (fractal->y < SIZE)
		{
			if (ft_strncmp(query, "mandelbrot", 11) == 0)
				calculate_mandelbrot(fractal);
			else if (ft_strncmp(query, "julia", 6) == 0)
				calculate_julia(fractal);
			// else if (ft_strcmp(query, "burningship") == 0)
			// 	calculate_burningship(fractal);
			fractal->y++;
		}
		fractal->x++;
		fractal->y = 0;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->window,
			fractal->image, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fractal	*fractal;

	if (argc != 2)
	{
		ft_putendl_fd("Usage: ./fractol <fractal>", 1);
		ft_putendl_fd("Available fractals: mandelbrot, julia, burningship", 1);
		return (0);
	}
	fractal = malloc(sizeof(t_fractal));
	init_fractal(fractal);
	init_mlx(fractal);
	mlx_key_hook(fractal->window, key_hook, fractal);
	mlx_mouse_hook(fractal->window, mouse_hook, fractal);
	draw_fractal(fractal, argv[1]);
	mlx_loop(fractal->mlx);
	return (0);
}
