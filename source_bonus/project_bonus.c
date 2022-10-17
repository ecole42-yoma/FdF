/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <codeyoma@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 22:16:03 by yongmkim          #+#    #+#             */
/*   Updated: 2022/04/29 14:23:43 by yongmkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"
#include <math.h>

void	iso(t_dot *v)
{
	int	previous_x;
	int	previous_y;

	previous_x = v->x;
	previous_y = v->y;
	v->x = (2 * (previous_x + previous_y));
	v->y = (-previous_x + previous_y) - (v->z);
}
/*	another Linear Rotation with i, j vertor unit (2, -1), (2, 1)
**	*x = (2 * (previous_x - previous_y));
**	*y = (previous_x + previous_y - z);
**
**	another logic with trigonometric functions
**	*x = (previous_x - previous_y) * cos(0.46373398);
**	*y = (previous_x + previous_y) * sin(0.46373398) - z;
*/

static void	rotate_x(int *y, int *z, double alpha)
{
	int	prev_y;

	prev_y = *y;
	*y = prev_y * cos(alpha) + (*z) * sin(alpha);
	*z = -prev_y * sin(alpha) + (*z) * cos(alpha);
}

static void	rotate_y(int *x, int *z, double beta)
{
	int	prev_x;

	prev_x = *x;
	*x = prev_x * cos(beta) + (*z) * sin(beta);
	*z = -prev_x * sin(beta) + (*z) * cos(beta);
}

static void	rotate_z(int *x, int *y, double gamma)
{
	int	prev_x;

	prev_x = *x;
	*x = prev_x * cos(gamma) - (*y) * sin(gamma);
	*y = prev_x * sin(gamma) + (*y) * cos(gamma);
}

void	ft_rotate_angle(t_dot *v, t_mlx *fdf)
{
	rotate_x(&v->y, &v->z, fdf->info->x_scalar);
	rotate_y(&v->x, &v->z, fdf->info->y_scalar);
	rotate_z(&v->x, &v->y, fdf->info->z_scalar);
}
