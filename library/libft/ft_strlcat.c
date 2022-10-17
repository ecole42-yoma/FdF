/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 23:18:23 by yongmkim          #+#    #+#             */
/*   Updated: 2022/03/21 16:07:09 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (!dst)
		return (0);
	while (*dst && i < dstsize)
	{
		dst++;
		i++;
	}
	if (!src)
		return (i);
	while (*src && i + 1 < dstsize)
	{
		*(dst++) = *(src++);
		i++;
	}
	if (i < dstsize)
		*dst = 0;
	while (*(src++))
		i++;
	return (i);
}
