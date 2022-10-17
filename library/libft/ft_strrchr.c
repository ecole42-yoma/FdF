/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <codeyoma@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 00:10:12 by yongmkim          #+#    #+#             */
/*   Updated: 2021/06/04 22:37:34 by yongmkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*temp;

	temp = NULL;
	while (1)
	{
		if (*s == (char)c)
			temp = (char *)s;
		if (*s == '\0')
		{
			if (*s == (char)c)
				return ((char *)s);
			return (temp);
		}
		s++;
	}
}
