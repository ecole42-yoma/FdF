/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <codeyoma@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 17:33:42 by yongmkim          #+#    #+#             */
/*   Updated: 2021/05/19 17:43:47 by yongmkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*temp;
	size_t	idx;

	if (!s || !f)
		return (NULL);
	temp = ft_strdup(s);
	if (!temp)
		return (NULL);
	idx = 0;
	while (temp[idx])
	{
		temp[idx] = f(idx, temp[idx]);
		idx++;
	}
	return (temp);
}
