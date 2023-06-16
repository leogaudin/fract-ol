/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudin <lgaudin@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:46:11 by lgaudin           #+#    #+#             */
/*   Updated: 2023/06/16 13:35:03 by lgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define SIZE 700
# define MAX_ITERATIONS 142

typedef struct s_fractal
{
	void	*mlx;
	void	*window;
	void	*image;
	void	*pointer_to_image;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		x;
	int		y;
	int		translated_x;
	int		translated_y;
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	int		max_iterations;
	int		color;
	double	offset_x;
	double	offset_y;
	double	zoom;
}			t_fractal;

# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <math.h>

// utils.c
void		translate_coordinates(t_fractal *fractal);
void		put_color_to_pixel(t_fractal *fractal, int x, int y, int color);

// init.c
void		init_fractal(t_fractal *fractal);
void		init_mlx(t_fractal *fractal);

// mandelbrot.c
void		calculate_mandelbrot(t_fractal *fractal);

#endif
