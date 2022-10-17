/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_util_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <codeyoma@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 01:16:27 by yongmkim          #+#    #+#             */
/*   Updated: 2022/04/29 14:52:10 by yongmkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"
#include "key_event.h"

int	close_fdf(t_mlx *fdf)
{
	ft_mlx_flush(fdf, 0);
	exit(0);
}

void	ft_key_scalar(int key, t_mlx *fdf)
{
	if (key == KC_H || key == KC_J || key == KC_K || key == KC_N || \
			key == KC_M || key == KC_COMM)
	{
		fdf->info->project = 3;
		if (key == KC_H)
			fdf->info->x_scalar += 0.1;
		if (key == KC_N)
			fdf->info->x_scalar -= 0.1;
		if (key == KC_J)
			fdf->info->y_scalar += 0.1;
		if (key == KC_M)
			fdf->info->y_scalar -= 0.1;
		if (key == KC_K)
			fdf->info->z_scalar += 0.1;
		if (key == KC_COMM)
			fdf->info->z_scalar -= 0.1;
	}
}

static void	ft_info_cpy_util(t_mlx *temp, int key)
{
	if (key & 2)
	{
		temp->info->x_scale = temp->info_save->x_scale;
		temp->info->y_scale = temp->info_save->y_scale;
		temp->info->z_scale = temp->info_save->z_scale;
		temp->info->scale = temp->info_save->scale;
		temp->info->project = temp->info_save->project;
		temp->info->x_scalar = temp->info_save->x_scalar;
		temp->info->y_scalar = temp->info_save->y_scalar;
		temp->info->z_scalar = temp->info_save->z_scalar;
	}
	if (key & 2 || key & 4)
	{
		temp->info->x_start = temp->info_save->x_start;
		temp->info->y_start = temp->info_save->y_start;
	}
}

void	ft_info_cpy(t_mlx *temp, int key)
{
	if (key & 1)
	{
		temp->info_save->x_scale = temp->info->x_scale;
		temp->info_save->y_scale = temp->info->y_scale;
		temp->info_save->z_scale = temp->info->z_scale;
		temp->info_save->x_scalar = temp->info->x_scalar;
		temp->info_save->y_scalar = temp->info->y_scalar;
		temp->info_save->z_scalar = temp->info->z_scalar;
		temp->info_save->scale = temp->info->scale;
		temp->info_save->x_start = temp->info->x_start;
		temp->info_save->y_start = temp->info->y_start;
		temp->info_save->project = temp->info->project;
	}
	else if (key & 2 || key & 4)
		ft_info_cpy_util(temp, key);
}
