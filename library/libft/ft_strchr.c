/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 00:04:13 by yongmkim          #+#    #+#             */
/*   Updated: 2022/04/23 01:49:00 by yongmkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strchr_pos(char *s, char sep)
{
	int	cnt;

	if (!s)
		return (0);
	cnt = 0;
	while (*s)
	{
		if (*s == sep)
			return (cnt);
		cnt++;
		s++;
	}
	return (0);
}

char	*ft_strchr(const char *s, int c)
{
	char	*temp;

	if (!s)
		return (NULL);
	temp = (char *)s;
	while (1)
	{
		if (*temp == (char)c)
			return (temp);
		if (*temp == '\0')
			return (NULL);
		temp++;
	}
}
