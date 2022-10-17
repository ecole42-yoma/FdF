/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <codeyoma@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 19:42:46 by yongmkim          #+#    #+#             */
/*   Updated: 2021/07/14 16:29:23 by yongmkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	void	*temp;
	size_t	idx;

	temp = ft_memchr(src, c, n);
	if (temp != NULL)
	{
		idx = temp - src + 1;
		return (ft_memcpy(dst, src, idx) + idx);
	}
	else
		ft_memcpy(dst, src, n);
	return (NULL);
}
