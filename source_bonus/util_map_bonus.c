/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <codeyoma@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 15:00:28 by yongmkim          #+#    #+#             */
/*   Updated: 2022/04/29 14:24:02 by yongmkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"
#include "libft.h"

t_dot	*fdf_atoi(char *str, int x, int y)
{
	t_dot	*temp;
	int		cnt;

	temp = malloc(sizeof(t_dot));
	if (temp == NULLL)
		return (NULLL);
	temp->x = x;
	temp->y = y;
	temp->z = ft_atoi_base(str, 10);
	cnt = ft_strchr_pos(str, ',');
	if (cnt == 0)
		temp->color = 0xffffff;
	else
		temp->color = ft_atoi_base(str + cnt + 1, 16);
	return (temp);
}

void	ft_mtm_util_second(int *y, t_list **mov, t_list **list)
{
	*y = -1;
	*mov = *list;
}

void	ft_mtm_util(char **split, int size, t_list **list)
{
	ft_matrix_free(split, size);
	(*list) = (*list)->next;
}
