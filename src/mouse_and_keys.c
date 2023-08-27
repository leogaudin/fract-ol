/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_and_keys.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 18:11:08 by lgaudin           #+#    #+#             */
/*   Updated: 2023/08/27 15:41:25 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

/**
 * @brief    Zooms or dezooms the fractal.
 *
 * @param    fractal
 * @param    x         The x coordinate of the mouse.
 * @param    y         The y coordinate of the mouse.
 * @param    zoom      1 for zoom, -1 for dezoom.
 */
void	zoom(t_fractal *fractal, int x, int y, int zoom)
{
	double	zoom_level;

	zoom_level = 1.42;
	if (zoom == 1)
	{
		fractal->offset_x = (x / fractal->zoom + fractal->offset_x) - (x
				/ (fractal->zoom * zoom_level));
		fractal->offset_y = (y / fractal->zoom + fractal->offset_y) - (y
				/ (fractal->zoom * zoom_level));
		fractal->zoom *= zoom_level;
	}
	else if (zoom == -1)
	{
		fractal->offset_x = (x / fractal->zoom + fractal->offset_x) - (x
				/ (fractal->zoom / zoom_level));
		fractal->offset_y = (y / fractal->zoom + fractal->offset_y) - (y
				/ (fractal->zoom / zoom_level));
		fractal->zoom /= zoom_level;
	}
	else
		return ;
}

/**
 * @brief    Sets the constants of Julia to random values.
 *
 * @param    cx        A pointer to the cx constant.
 * @param    cy        A pointer to the cy constant.
 */
void	set_random_julia(double *cx, double *cy)
{
	*cx = generate_random_c();
	*cy = generate_random_c();
}

/**
 * @brief    The handler for keyboard events.
 * 				ESC: exit the program.
 * 				LEFT: move the fractal to the left.
 * 				RIGHT: move the fractal to the right.
 * 				UP: move the fractal up.
 * 				DOWN: move the fractal down.
 * 				R: reset the fractal.
 * 				C: change the color scheme.
 * 				J: set the constants of Julia to random values.
 * 				P: increase the max iterations.
 * 				M: reduce the max iterations.
 *
 * @param    key_code
 * @param    fractal
 */
int	key_hook(int key_code, t_fractal *fractal)
{
	if (key_code == ESC)
		exit(1);
	else if (key_code == LEFT)
		fractal->offset_x -= 42 / fractal->zoom;
	else if (key_code == RIGHT)
		fractal->offset_x += 42 / fractal->zoom;
	else if (key_code == UP)
		fractal->offset_y -= 42 / fractal->zoom;
	else if (key_code == DOWN)
		fractal->offset_y += 42 / fractal->zoom;
	else if (key_code == R)
		init_fractal(fractal);
	else if (key_code == C)
		fractal->color += (255 * 255 * 255) / 100;
	else if (key_code == J)
		set_random_julia(&fractal->cx, &fractal->cx);
	else if (key_code == M || key_code == P)
		change_iterations(fractal, key_code);
	draw_fractal(fractal, fractal->name);
	return (0);
}

/**
 * @brief    The handler for mouse events.
 * 				SCROLL_UP: zoom in.
 * 				SCROLL_DOWN: zoom out.
 *
 * @param    mouse_code The code of the mouse event.
 * @param    x          The x coordinate of the mouse.
 * @param    y          The y coordinate of the mouse.
 * @param    fractal
 */
int	mouse_hook(int mouse_code, int x, int y, t_fractal *fractal)
{
	if (mouse_code == SCROLL_UP)
		zoom(fractal, x, y, 1);
	else if (mouse_code == SCROLL_DOWN)
		zoom(fractal, x, y, -1);
	draw_fractal(fractal, fractal->name);
	return (0);
}
