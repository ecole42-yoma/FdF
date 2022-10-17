/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <codeyoma@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 19:28:51 by yongmkim          #+#    #+#             */
/*   Updated: 2021/07/14 16:28:53 by yongmkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*temp_dst;

	if (!src && !dst)
		return (NULL);
	temp_dst = (unsigned char *)dst;
	while (n--)
	{
		*(temp_dst++) = *((unsigned char *)src++);
	}
	return (dst);
}
