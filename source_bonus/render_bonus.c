/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <codeyoma@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 16:55:37 by yongmkim          #+#    #+#             */
/*   Updated: 2022/04/29 14:23:49 by yongmkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"
#include "mlx.h"
#include <math.h>
#include "libft.h"

static t_dot	cam_modi_dot(t_dot *v1, t_mlx *fdf)
{
	t_dot	temp;

	temp.x = (((float)v1->x * (float)fdf->info->scale) * fdf->info->x_scale);
	temp.y = (((float)v1->y * (float)fdf->info->scale) * fdf->info->y_scale);
	temp.z = ((float)v1->z * (float)fdf->info->scale * fdf->info->z_scale * \
			2);
	if (fdf->info->project & 2)
		ft_rotate_angle(&temp, fdf);
	if (fdf->info->project & 1)
		iso(&temp);
	temp.color = v1->color;
	temp.x += fdf->info->x_start;
	temp.y += fdf->info->y_start;
	return (temp);
}

void	ft_put_pixel(t_mlx *fdf, int x, int y, int color)
{
	char	*temp;
	int		idx;

	if (x < 0 || y < 0 || x >= HD_WIDTH || y >= HD_HEIGHT)
		return ;
	idx = (y * fdf->size) + (x * (fdf->bpp / 8));
	temp = fdf->img_addr + idx;
	*(unsigned int *)temp = color;
}

static void	ft_img_clear(t_mlx *fdf)
{
	int	i;
	int	size;
	int	*temp;

	i = 0;
	size = HD_WIDTH * HD_HEIGHT;
	temp = (int *)(fdf->img_addr);
	while (i < size)
	{
		temp[i] = 0x1A1A1A;
		++i;
	}
}

static void	draw_line_garosero(int x, int y, t_mlx *fdf, int key)
{
	t_dot	*v1;
	t_dot	*v2;

	v1 = fdf->map->matrix[(fdf->map->width * y) + x];
	if (key & 1)
		v2 = fdf->map->matrix[(fdf->map->width * y) + (x + 1)];
	else
		v2 = fdf->map->matrix[(fdf->map->width * (y + 1)) + (x)];
	ft_line_draw(cam_modi_dot(v1, fdf), cam_modi_dot(v2, fdf), fdf);
}

void	ft_render(t_mlx *fdf)
{
	int	x;
	int	y;

	ft_img_clear(fdf);
	y = -1;
	while (++y < fdf->map->height)
	{
		x = -1;
		while (++x < fdf->map->width)
		{
			if (x != fdf->map->width - 1)
				draw_line_garosero(x, y, fdf, 1);
			if (y != fdf->map->height - 1)
				draw_line_garosero(x, y, fdf, 2);
		}
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
}
