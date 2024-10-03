/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <pabad-ap@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 15:32:54 by pabad-ap          #+#    #+#             */
/*   Updated: 2024/05/20 18:12:06 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <unistd.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>

# include "./lib/libft/libft.h"
# include "./lib/minilibx_macos/mlx.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5000
# endif

# ifndef DEFAULT_COLOR
#  define DEFAULT_COLOR 16777215
# endif

# ifndef WIN_H
#  define WIN_H 1000
# endif

# ifndef WIN_W
#  define WIN_W 1000
# endif

//key codes
# define ESC 53
# define ARROW_LEFT 123
# define ARROW_RIGHT 124
# define ARROW_DOWN 125
# define ARROW_UP 126
# define ON_DESTROY 17

typedef struct s_file_data
{
	char	*buff;
	int		fst_line_items;
	int		curr_line_items;
	int		fd;
	int		lines;
}	t_file_data;

typedef struct s_point_data
{
	int	x;
	int	y;
	int	z;
	int	color;
	int	iso_x;
	int	iso_y;
}	t_point_data;

typedef struct s_line_data
{
	int	dy;
	int	dx;
	int	inc_yi;
	int	inc_xi;
	int	inc_ys;
	int	inc_xs;
	int	av_s;
	int	av;
	int	av_i;
}		t_line_data;

typedef struct s_canvas_data
{
	void			*mlx_init;
	void			*mlx_win;
	void			*img;
	char			*fst_img_pixel;
	int				bpp;
	int				line_bytes;
	int				endian;
	float			scaler_x;
	float			scaler_y;
	unsigned int	color;
	int				min_x;
	int				max_x;
	int				min_y;
	int				max_y;
}					t_canvas_data;

t_file_data		ft_input_checks(const char *filename);
void			ft_exit_with_msg(char *msg);
char			*get_next_line(int fd);
size_t			ft_gnl_strlen(const char *s);
char			*ft_gnl_strjoin(char *s1, char *s2);
char			*ft_gnl_strchr(const char *s, int c);
char			*ft_gnl_substr(char const *s, unsigned int start, size_t len);
char			*ft_gnl_strdup(char *s1);
int				ft_str_to_int(char *str);
t_point_data	*ft_fill_point_details(char **items_line, int y_pos, int width);
t_point_data	**ft_matrix_factory(char *file, int lines, int line_items);
void			free_inside_split(char **s);
void			ft_line_bresenham(t_point_data p1, t_point_data p2, \
		t_canvas_data *c);
void			ft_draw_pixel(int x, int y, int color, t_canvas_data *canvas);
t_canvas_data	init_env(void);
void			ft_iso_point(t_point_data **point, t_file_data f, \
		t_canvas_data *canvas);
int				ft_keys_handler(int keycode, t_canvas_data *canvas);
int				ft_events_handler(t_canvas_data *canvas);

#endif
