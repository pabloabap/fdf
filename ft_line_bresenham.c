/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_bresenham.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <pabad-ap@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 19:09:24 by pabad-ap          #+#    #+#             */
/*   Updated: 2024/05/20 17:30:46 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_movements(t_line_data *line);
static void	ft_err_uploader(t_line_data *line);
static void	ft_render_line(t_point_data p1, t_point_data p2, \
		t_canvas_data *c, t_line_data line);
static void	ft_update_after_draw(t_line_data *line, int *x, int *y);

void	ft_line_bresenham(t_point_data p1, t_point_data p2, t_canvas_data *c)
{
	t_line_data	line;

	line.dx = (p2.iso_x - p1.iso_x);
	line.dy = (p2.iso_y - p1.iso_y);
	ft_movements(&line);
	if (line.dy > line.dx)
	{
		line.av = line.dx;
		line.dx = line.dy;
		line.dy = line.av;
	}
	ft_err_uploader(&line);
	ft_render_line(p1, p2, c, line);
	return ;
}

static void	ft_movements(t_line_data *line)
{
	if (line->dx >= 0)
		line->inc_xi = 1;
	else
	{
		line->inc_xi = -1;
		line->dx = -line->dx;
	}
	if (line->dy >= 0)
		line->inc_yi = 1;
	else
	{
		line->inc_yi = -1;
		line->dy = -line->dy;
	}
	if (line->dx >= line->dy)
	{
		line->inc_ys = 0;
		line->inc_xs = line->inc_xi;
	}
	else
	{
		line->inc_ys = line->inc_yi;
		line->inc_xs = 0;
	}
	return ;
}

static void	ft_err_uploader(t_line_data *line)
{
	line->av_s = 2 * line->dy;
	line->av = line->av_s - line->dx;
	line->av_i = line->av - line->dx;
	return ;
}

static void	ft_render_line(t_point_data p1, t_point_data p2, \
		t_canvas_data *c, t_line_data line)
{
	int			x;
	int			y;

	x = p1.iso_x;
	y = p1.iso_y;
	if (p1.iso_x != p2.iso_x)
	{
		while (x != p2.iso_x)
		{
			ft_draw_pixel(x, y, p1.color, c);
			ft_update_after_draw(&line, &x, &y);
		}
		ft_draw_pixel(x, y, p1.color, c);
	}
	else if (p1.iso_y != p2.iso_y)
	{
		while (y < p2.iso_y)
		{
			ft_draw_pixel(x, y, p1.color, c);
			ft_update_after_draw(&line, &x, &y);
		}
		ft_draw_pixel(x, y, p1.color, c);
	}
	return ;
}

static void	ft_update_after_draw(t_line_data *line, int *x, int *y)
{
	if (line->av >= 0)
	{
		*x = (*x + line->inc_xi);
		*y = (*y + line->inc_yi);
		line->av = line->av + line->av_i;
	}
	else
	{
		*x = (*x + line->inc_xs);
		*y = (*y + line->inc_ys);
		line->av = line->av + line->av_s;
	}
	return ;
}
