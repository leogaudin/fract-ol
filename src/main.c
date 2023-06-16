/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 22:55:04 by lgaudin           #+#    #+#             */
/*   Updated: 2023/06/16 13:37:24 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	draw_fractal(t_fractal *fractal, char *query)
{
	while (fractal->x < SIZE)
	{
		while (fractal->y < SIZE)
		{
			translate_coordinates(fractal);
			if (ft_strncmp(query, "mandelbrot", 11) == 0)
				calculate_mandelbrot(fractal);
			// else if (ft_strcmp(query, "julia") == 0)
			// 	calculate_julia(fractal);
			// else if (ft_strcmp(query, "burningship") == 0)
			// 	calculate_burningship(fractal);
			fractal->y++;
		}
		fractal->x++;
		fractal->y = 0;
	}
}

int	main(void)
{
	t_fractal	*fractal;

	fractal = malloc(sizeof(t_fractal));
	init_fractal(fractal);
	init_mlx(fractal);
	draw_fractal(fractal, "mandelbrot");
	mlx_loop(fractal->mlx);
	return (0);
}
