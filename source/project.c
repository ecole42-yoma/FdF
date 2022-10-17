/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <codeyoma@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 22:16:03 by yongmkim          #+#    #+#             */
/*   Updated: 2022/04/29 14:31:08 by yongmkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
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
