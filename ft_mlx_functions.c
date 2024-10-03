/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <pabad-ap@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 15:48:43 by pabad-ap          #+#    #+#             */
/*   Updated: 2024/05/20 14:52:18 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
#include "./lib/minilibx_macos/mlx.h"
//#include "./lib/minilibx_linux/mlx.h"

t_canvas_data	init_env(void)
{
	t_canvas_data	canvas;

	canvas.mlx_init = mlx_init();
	canvas.scaler_x = 1;
	canvas.scaler_y = 1;
	canvas.min_x = 0;
	canvas.max_x = 0;
	canvas.min_y = 0;
	canvas.max_y = 0;
	canvas.mlx_win = mlx_new_window(canvas.mlx_init, WIN_W, WIN_H, "fdf");
	canvas.img = mlx_new_image(canvas.mlx_init, WIN_W, WIN_H);
	canvas.fst_img_pixel = mlx_get_data_addr(canvas.img, &(canvas.bpp), \
			&(canvas.line_bytes), &(canvas.endian));
	return (canvas);
}

void	ft_draw_pixel(int x, int y, int color, t_canvas_data *canvas)
{
	char	*pixel_in_window;

	canvas->color = mlx_get_color_value(canvas->mlx_init, color);
	pixel_in_window = canvas->fst_img_pixel + (y * canvas->line_bytes \
			+ x * (canvas->bpp / 8));
	*(unsigned int *)pixel_in_window = canvas->color;
	return ;
}
