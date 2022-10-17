/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <codeyoma@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:45:05 by yongmkim          #+#    #+#             */
/*   Updated: 2022/04/29 14:22:49 by yongmkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static float	ft_linear_percent(float x, float v1, float v2)
{
	if (x == v1)
		return (0.0);
	if (x == v2)
		return (1.0);
	return ((x - v1) / (v2 - v1));
}

static int	ft_color_linear_percent(int color1, int color2, float percent)
{
	if (color1 == color2)
		return (color1);
	return (((float)color1 + ((color2 - color1) * percent)));
}

static int	get_color_gradient(int color1, int color2, float percent)
{
	int	red;
	int	green;
	int	blue;

	if (color1 == color2)
		return (color1);
	red = ft_color_linear_percent((color1 >> 16) & 0xff, (color2 >> 16) & \
			0xff, percent);
	green = ft_color_linear_percent((color1 >> 8) & 0xff, (color2 >> 8) & \
			0xff, percent);
	blue = ft_color_linear_percent(color1 & 0xff, color2 & 0xff, percent);
	return (red << 16 | green << 8 | blue);
}

static void	ft_draw_init(t_draw *draw, t_dot v1, t_dot v2)
{
	draw->dx = ft_abs(v2.x - v1.x);
	if (v1.x < v2.x)
		draw->sx = 1;
	else
		draw->sx = -1;
	draw->dy = ft_abs(v2.y - v1.y);
	if (v1.y < v2.y)
		draw->sy = 1;
	else
		draw->sy = -1;
	if (draw->dx > draw->dy)
		draw->err = draw->dx / 2;
	else
		draw->err = -draw->dy / 2;
	draw->x = v1.x;
	draw->y = v1.y;
}

void	ft_line_draw(t_dot v1, t_dot v2, t_mlx *fdf)
{
	t_draw	draw;
	float	percent;

	ft_draw_init(&draw, v1, v2);
	while (1)
	{
		percent = ft_linear_percent(draw.x, v1.x, v2.x);
		ft_put_pixel(fdf, draw.x, draw.y, get_color_gradient(v1.color, \
					v2.color, percent));
		if (draw.x == v2.x && draw.y == v2.y)
			break ;
		draw.e2 = draw.err;
		if (draw.e2 > -draw.dx)
		{
			draw.err -= draw.dy;
			draw.x += draw.sx;
		}
		if (draw.e2 < draw.dy)
		{
			draw.err += draw.dx;
			draw.y += draw.sy;
		}
	}
}
