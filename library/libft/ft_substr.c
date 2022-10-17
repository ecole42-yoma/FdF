/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <codeyoma@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 20:23:46 by yongmkim          #+#    #+#             */
/*   Updated: 2021/07/14 16:25:05 by yongmkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*temp;

	if (!s)
		return (NULL);
	if ((unsigned int)ft_strlen(s) <= start)
		return (ft_strdup(""));
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	temp = ft_calloc(len + 1, sizeof(char));
	if (!temp)
		return (NULL);
	temp[len] = 0;
	ft_memcpy(temp, s + start, len);
	return (temp);
}
