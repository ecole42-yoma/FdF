/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <codeyoma@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 22:47:20 by yongmkim          #+#    #+#             */
/*   Updated: 2021/07/14 16:29:46 by yongmkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int	temp;

	while (n--)
	{
		temp = *((unsigned char *)s1++) - *((unsigned char *)s2++);
		if (temp)
			return (temp);
	}
	return (0);
}
