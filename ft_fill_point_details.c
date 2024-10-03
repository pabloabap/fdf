/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_point_details.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <pabad-ap@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 15:05:08 by pabad-ap          #+#    #+#             */
/*   Updated: 2024/05/20 17:26:29 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "./lib/libft/libft.h"

t_point_data	*ft_fill_point_details(char **items_line, int y_pos, int wdth);
t_point_data	**ft_matrix_factory(char *file, int lines, int line_items);

t_point_data	**ft_matrix_factory(char *file, int lines, int line_items)
{
	int				fd;
	char			*line;
	char			**arr_line_items;
	t_point_data	**p;
	int				i;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_exit_with_msg("Error opening the file");
	p = (t_point_data **)malloc(lines * sizeof(t_point_data *));
	if (p == NULL)
		ft_exit_with_msg("Malloc error");
	i = 0;
	while (i < lines)
	{
		line = get_next_line(fd);
		arr_line_items = ft_split_gnl(line, ' ');
		p[i] = ft_fill_point_details(arr_line_items, i, line_items);
		free_inside_split(arr_line_items);
		free(arr_line_items);
		free(line);
		i++;
	}
	return (p);
}

t_point_data	*ft_fill_point_details(char **items_line, int y_pos, int wdth)
{
	int				i;
	char			*comma;
	t_point_data	*line;

	i = 0;
	line = (t_point_data *)malloc(wdth * sizeof(t_point_data));
	while (items_line[i])
	{
		line[i].x = i;
		line[i].y = y_pos;
		line[i].z = ft_atoi(items_line[i]);
		line[i].color = DEFAULT_COLOR;
		comma = ft_strchr(items_line[i], ',');
		if (comma)
			line[i].color = ft_str_to_int(comma + 1);
		i ++;
	}
	return (line);
}
