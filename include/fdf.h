/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <codeyoma@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:50:16 by yongmkim          #+#    #+#             */
/*   Updated: 2022/04/29 14:32:02 by yongmkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define HD_WIDTH 1920
# define HD_HEIGHT 1050

# include "libft.h"

typedef struct s_info
{
	char	*title;
	float	x_scale;
	float	y_scale;
	float	z_scale;
	int		scale;
	int		horizontal;
	int		vertical;
	int		x_start;
	int		y_start;
	int		project;
}			t_info;

typedef struct s_dot
{
	int		x;
	int		y;
	int		z;
	int		color;
}			t_dot;

typedef struct s_draw
{
	int		x;
	int		y;
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		err;
	int		e2;
}			t_draw;

typedef struct s_map
{
	int		width;
	int		height;
	int		min_altitude;
	int		max_altitude;
	t_dot	**matrix;
}			t_map;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*img_addr;
	int		bpp;
	int		size;
	int		endian;
	t_map	*map;
	t_info	*info;
}			t_mlx;

/*	Main Func
**=============================================================================
*/
void		ft_event_handler(t_mlx *fdf);

/*	file to matrix
**=============================================================================
*/
void		ft_map_consistency(char **argv, t_map **map);
t_dot		*fdf_atoi(char *str, int x, int y);
void		ft_min_max_altitude(t_map **map);

/*	Rendering
**=============================================================================
*/
void		iso(t_dot *v);
void		ft_render(t_mlx *fdf);
void		ft_line_draw(t_dot v1, t_dot v2, t_mlx *fdf);
void		ft_put_pixel(t_mlx *fdf, int x, int y, int color);

/*	Error handle
**=============================================================================
*/
void		ft_mlx_flush(t_mlx *temp, int key);
void		ft_memflush(void **target);
void		ft_error_handler(int key, char *str);
void		ft_argument_consistency(int argc);

/*	Util handle
**=============================================================================
*/
void		ft_print_dot(t_mlx *fdf);
void		ft_mtm_util(char **split, int size, t_list **list);
void		ft_mtm_util_second(int *y, t_list **mov, t_list **list);
void		ft_starting_point(t_mlx *temp);

#endif
