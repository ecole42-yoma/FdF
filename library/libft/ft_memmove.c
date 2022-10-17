/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <codeyoma@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 19:54:09 by yongmkim          #+#    #+#             */
/*   Updated: 2021/07/14 16:28:46 by yongmkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (!dst && !src)
		return (NULL);
	if (dst < src)
	{
		return (ft_memcpy(dst, src, len));
	}
	else
	{
		while (len--)
			*((unsigned char *)dst + len) = *((unsigned char *)src + len);
	}
	return (dst);
}
