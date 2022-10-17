/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_issort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:15:49 by yongmkim          #+#    #+#             */
/*   Updated: 2022/03/09 11:31:09 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_issort_des(ssize_t *nbr, ssize_t size)
{
	ssize_t	cnt;

	if (size <= 0)
		return (ERROR);
	cnt = 1;
	while (cnt < size)
	{
		if (nbr[cnt - 1] >= nbr[cnt])
			cnt++;
		else
			return (ERROR);
	}
	if (cnt == size)
		return (SUCCESS);
	return (ERROR);
}

int	ft_issort_asc(ssize_t *nbr, ssize_t size)
{
	ssize_t	cnt;

	if (size <= 0)
		return (ERROR);
	cnt = 1;
	while (cnt < size)
	{
		if (nbr[cnt - 1] <= nbr[cnt])
			cnt++;
		else
			return (ERROR);
	}
	if (cnt == size)
		return (SUCCESS);
	return (ERROR);
}
