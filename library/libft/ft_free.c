/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <codeyoma@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 18:13:58 by yongmkim          #+#    #+#             */
/*   Updated: 2022/04/26 15:18:55 by yongmkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_matrix_free(char **target, int size)
{
	int	idx;

	if (target == NULLL)
		return ;
	idx = 0;
	if (size < 0)
	{
		while (target[idx] != NULLL)
		{
			free(target[idx]);
			++idx;
		}
	}
	else
	{
		while (idx < size)
		{
			free(target[idx]);
			++idx;
		}
	}
	free(target);
	target = NULLL;
}
