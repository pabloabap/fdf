/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <pabad-ap@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:45:36 by pabad-ap          #+#    #+#             */
/*   Updated: 2024/05/20 15:03:35 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_keys_handler(int keycode, t_canvas_data *canvas)
{
	if (keycode == ESC)
	{
		mlx_destroy_image(canvas->mlx_init, canvas->img);
		mlx_destroy_window(canvas->mlx_init, canvas->mlx_win);
		exit(0);
	}
	return (0);
}

int	ft_events_handler(t_canvas_data *canvas)
{
	mlx_destroy_image(canvas->mlx_init, canvas->img);
	mlx_destroy_window(canvas->mlx_init, canvas->mlx_win);
	exit(0);
	return (0);
}
