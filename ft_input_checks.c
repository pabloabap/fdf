/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_checks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <pabad-ap@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 14:49:29 by pabad-ap          #+#    #+#             */
/*   Updated: 2024/05/20 17:53:51 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "./lib/libft/libft.h"

static void	ft_right_filename_ext(const char *filename);
static void	ft_check_file_content(const char *filename, t_file_data *f_data);
static void	ft_process_buffer(t_file_data *f_data);

t_file_data	ft_input_checks(const char *filename)
{
	t_file_data	f_data;

	f_data.lines = 0;
	f_data.curr_line_items = 0;
	ft_right_filename_ext(filename);
	ft_check_file_content(filename, &f_data);
	return (f_data);
}

static void	ft_right_filename_ext(const char *filename)
{
	int		i;
	int		j;
	char	*ext;

	i = 0;
	j = 0;
	ext = ".fdf";
	while (filename[i])
		i ++;
	j = i - 4;
	while (j < i)
	{
		if (filename[j] == *ext)
			ext++;
		else
			ft_exit_with_msg("ERROR : Not .fdf file");
		j ++;
	}
}

static void	ft_check_file_content(const char *filename, t_file_data *f_data)
{
	f_data->fd = open(filename, O_RDONLY);
	if (f_data->fd < 0)
		ft_exit_with_msg("Error on file opening");
	f_data->buff = get_next_line(f_data->fd);
	f_data->lines = 0;
	f_data->fst_line_items = 0;
	f_data->curr_line_items = 0;
	while (f_data->buff)
		ft_process_buffer(f_data);
	free(f_data->buff);
	if (close(f_data->fd) < 0)
		ft_exit_with_msg("Error clossing the file");
}

static void	ft_process_buffer(t_file_data *f_data)
{
	char	**line_splited;
	int		i;

	i = 0;
	line_splited = ft_split_gnl(f_data->buff, ' ');
	f_data->curr_line_items = 0;
	while (line_splited[i++])
	{
		if (f_data->lines == 0)
			f_data->fst_line_items ++;
		else
			f_data->curr_line_items ++;
	}
	free_inside_split(line_splited);
	free(line_splited);
	line_splited = NULL;
	if (f_data->lines != 0 && \
			f_data->curr_line_items != f_data->fst_line_items)
		ft_exit_with_msg("Different number of items per line");
	f_data->lines++;
	free(f_data->buff);
	f_data->buff = get_next_line(f_data->fd);
}
