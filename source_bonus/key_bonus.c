/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <codeyoma@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 19:07:50 by yongmkim          #+#    #+#             */
/*   Updated: 2022/04/29 17:12:11 by yongmkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"
#include "mlx.h"
#include "key_event.h"

static void	ft_key_project(int key, t_mlx *fdf)
{
	if (key == KC_P)
		fdf->info->project = 0;
	if (key == KC_I)
		fdf->info->project = 1;
}

static void	ft_key_scale(int key, t_mlx *fdf)
{
	if (key == KC_PPLS)
		fdf->info->scale += 1;
	if (key == KC_MINUS)
	{
		fdf->info->scale -= 1;
		if (fdf->info->scale <= 1)
			fdf->info->scale = 1;
	}
	if (key == KC_A)
		fdf->info->x_scale += 0.1;
	if (key == KC_Z)
		fdf->info->x_scale -= 0.1;
	if (key == KC_S)
		fdf->info->y_scale += 0.1;
	if (key == KC_X)
		fdf->info->y_scale -= 0.1;
	if (key == KC_D)
		fdf->info->z_scale += 0.1;
	if (key == KC_C)
		fdf->info->z_scale -= 0.1;
}

static void	ft_key_move(int key, t_mlx *fdf)
{
	if (key == KC_LEFT)
		fdf->info->x_start += 42;
	if (key == KC_RIGHT)
		fdf->info->x_start -= 42;
	if (key == KC_DOWN)
		fdf->info->y_start -= 42;
	if (key == KC_UP)
		fdf->info->y_start += 42;
}

static int	key_press(int key, t_mlx *fdf)
{
	if (key == KC_ESC)
	{
		ft_mlx_flush(fdf, 0);
		exit(0);
	}
	if (key == KC_R)
		ft_info_cpy(fdf, 2);
	if (key == KC_T)
		ft_info_cpy(fdf, 4);
	if (key == KC_G)
	{
		ft_print_dot(fdf);
		return (1);
	}
	ft_key_project(key, fdf);
	ft_key_scalar(key, fdf);
	ft_key_scale(key, fdf);
	ft_key_move(key, fdf);
	ft_render(fdf);
	return (1);
}

void	ft_event_handler(t_mlx *fdf)
{
	mlx_hook(fdf->win, KEY_PRESS, 0, key_press, fdf);
	mlx_hook(fdf->win, DESTROY_NOTIFY, 0, close_fdf, fdf);
}
