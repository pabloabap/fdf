/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <pabad-ap@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 14:51:56 by pabad-ap          #+#    #+#             */
/*   Updated: 2024/05/20 18:31:18 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_draw_x_lines(t_file_data f_data, \
		t_canvas_data canvas, t_point_data **p);
static void	ft_draw_y_lines(t_file_data f_data, \
		t_canvas_data canvas, t_point_data **p);

int	main(int argc, char **argv)
{
	t_file_data		f_data;
	t_point_data	**p;
	t_canvas_data	canvas;

	if (argc == 2)
	{
		f_data = ft_input_checks(argv[1]);
		p = ft_matrix_factory(argv[1], f_data.lines, f_data.fst_line_items);
		canvas = init_env();
		ft_iso_point(p, f_data, &canvas);
		ft_draw_x_lines(f_data, canvas, p);
		ft_draw_y_lines(f_data, canvas, p);
		mlx_put_image_to_window(canvas.mlx_init, \
				canvas.mlx_win, canvas.img, 50, 50);
		mlx_key_hook(canvas.mlx_win, ft_keys_handler, &canvas);
		mlx_hook(canvas.mlx_win, ON_DESTROY, 0, ft_events_handler, &canvas);
		mlx_loop(canvas.mlx_init);
	}
	else
		ft_printf("Usage : ./fdf <filename.fdf>\n");
	return (0);
}

static void	ft_draw_x_lines(t_file_data f_data, \
		t_canvas_data canvas, t_point_data **p)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < f_data.lines)
	{
		while (x < f_data.fst_line_items)
		{
			if (x < f_data.fst_line_items - 1)
				ft_line_bresenham(p[y][x], p[y][x + 1], &canvas);
			x++;
		}
		x = 0;
		y ++;
	}
}

static void	ft_draw_y_lines(t_file_data f_data, \
		t_canvas_data canvas, t_point_data **p)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < f_data.fst_line_items)
	{
		while (y < f_data.lines)
		{
			if (y < f_data.lines - 1)
				ft_line_bresenham(p[y][x], p[y + 1][x], &canvas);
			y++;
		}
		y = 0;
		x ++;
	}
}
