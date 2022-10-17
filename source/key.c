/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <codeyoma@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 19:07:50 by yongmkim          #+#    #+#             */
/*   Updated: 2022/04/29 17:11:33 by yongmkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "key_event.h"

static int	key_press(int key, t_mlx *fdf)
{
	if (key == KC_ESC)
	{
		ft_mlx_flush(fdf, 0);
		exit(0);
	}
	if (key == KC_G)
	{
		ft_print_dot(fdf);
		return (1);
	}
	ft_render(fdf);
	return (1);
}

static int	close_fdf(t_mlx *fdf)
{
	ft_mlx_flush(fdf, 0);
	exit(0);
}

void	ft_event_handler(t_mlx *fdf)
{
	mlx_hook(fdf->win, KEY_PRESS, 0, key_press, fdf);
	mlx_hook(fdf->win, DESTROY_NOTIFY, 0, close_fdf, fdf);
}
