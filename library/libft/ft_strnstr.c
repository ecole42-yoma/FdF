/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <codeyoma@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 00:20:23 by yongmkim          #+#    #+#             */
/*   Updated: 2021/07/14 16:26:21 by yongmkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	need_len;
	size_t	hay_len;

	hay_len = ft_strlen(haystack);
	need_len = ft_strlen(needle);
	if (need_len == 0)
		return ((char *)haystack);
	if ((need_len > len) || (hay_len == 0) || (need_len > hay_len))
		return (NULL);
	if (hay_len < len)
		len = hay_len;
	while (len >= need_len)
	{
		if (ft_strncmp(haystack, needle, need_len) == 0)
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
