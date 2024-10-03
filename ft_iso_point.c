/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iso_point.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <pabad-ap@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:42:17 by pabad-ap          #+#    #+#             */
/*   Updated: 2024/05/20 18:15:40 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_conversion(t_point_data *point, t_canvas_data *canvas);
static void	ft_scaler(t_point_data **point, int w, int h, \
		t_canvas_data *canvas);

void	ft_iso_point(t_point_data **point, t_file_data f, t_canvas_data *canvas)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < f.lines)
	{
		while (j < f.fst_line_items)
		{
			ft_conversion(&(point[i][j]), canvas);
			j ++;
		}
		j = 0;
		i ++;
	}
	canvas->max_x -= canvas->min_x;
	canvas->max_y -= canvas->min_y;
	ft_scaler(point, f.fst_line_items, f.lines, canvas);
}

static void	ft_conversion(t_point_data *point, t_canvas_data *canvas)
{
	point->iso_x = round((point->x - point->y) * cos(0.46365) * 100);
	if (point->iso_x < canvas->min_x)
		canvas->min_x = point->iso_x;
	if (point->iso_x > canvas->max_x)
		canvas->max_x = point->iso_x;
	point->iso_y = round(\
			(-point->z + (point->x + point->y) * sin(0.46365)) * 100);
	if (point->iso_y < canvas->min_y)
		canvas->min_y = point->iso_y;
	if (point->iso_y > canvas->max_y)
		canvas->max_y = point->iso_y;
}

static void	ft_scaler(t_point_data **point, int w, int h, t_canvas_data *canvas)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	canvas->scaler_x = WIN_W * 0.8 / canvas->max_x;
	canvas->scaler_y = WIN_H * 0.8 / canvas->max_y;
	while (i < h)
	{
		while (j < w)
		{
			point[i][j].iso_x = round(\
					(point[i][j].iso_x - canvas->min_x) * canvas->scaler_x);
			point[i][j].iso_y = round(\
					(point[i][j].iso_y - canvas->min_y) * canvas->scaler_y);
			j ++;
		}
		j = 0;
		i ++;
	}
}
