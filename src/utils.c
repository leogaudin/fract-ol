/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 13:27:37 by lgaudin           #+#    #+#             */
/*   Updated: 2023/06/16 13:36:48 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	translate_coordinates(t_fractal *fractal)
{
	fractal->translated_x = fractal->x - SIZE / 2;
	fractal->translated_y = SIZE / 2 - fractal->y;
}

void	put_color_to_pixel(t_fractal *fractal, int x, int y, int color)
{
	mlx_pixel_put(fractal->mlx, fractal->window, x, y,
		mlx_get_color_value(fractal->mlx, color));
}
