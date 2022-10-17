/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <codeyoma@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 16:11:42 by yongmkim          #+#    #+#             */
/*   Updated: 2022/04/29 14:23:56 by yongmkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf_bonus.h"

void	ft_print_dot(t_mlx *fdf)
{
	int		x;
	int		y;

	y = 0;
	ft_printf("print - matrix - start\n");
	while (y < fdf->map->height)
	{
		x = 0;
		ft_printf("[ %d ] : ", y);
		while (x < fdf->map->width)
		{
			ft_printf("[%d]", fdf->map->matrix[(y * fdf->map->width) + x]->z);
			++x;
		}
		ft_printf("\n");
		++y;
	}
	ft_printf("print - matrix - end\n");
	ft_printf("map height: %d\n", fdf->map->height);
	ft_printf("map width: %d\n", fdf->map->width);
	ft_printf("altitude max: %d\n", fdf->map->max_altitude);
	ft_printf("altitude min: %d\n", fdf->map->min_altitude);
}

void	ft_min_max_altitude(t_map **map)
{
	int	x;
	int	y;
	int	size;

	(*map)->min_altitude = (*map)->matrix[0]->z;
	(*map)->max_altitude = (*map)->matrix[0]->z;
	y = -1;
	while (++y < (*map)->height)
	{
		x = -1;
		while (++x < (*map)->width)
		{
			size = (*map)->matrix[(y * (*map)->width) + x]->z;
			if ((*map)->max_altitude < size)
				(*map)->max_altitude = size;
			if ((*map)->min_altitude > size)
				(*map)->min_altitude = size;
		}
	}
}

void	ft_starting_point(t_mlx *temp)
{
	temp->info_save = (t_info *)malloc(sizeof(t_info));
	if (temp->info_save == NULLL)
		ft_mlx_flush(temp, STD_ERR);
	temp->info->scale = ft_min(temp->info->x_scale, temp->info->y_scale);
	temp->info->x_start = (HD_WIDTH / 2) - \
						(temp->map->height * temp->info->scale * 2);
	temp->info->y_start = HD_HEIGHT - (temp->map->height * temp->info->scale * \
			1.2);
	temp->info->x_scale = 1;
	temp->info->y_scale = 1;
	temp->info->project = 1;
	temp->info->x_scalar = 0;
	temp->info->y_scalar = 0;
	temp->info->z_scalar = 0;
	ft_info_cpy(temp, 1);
}
