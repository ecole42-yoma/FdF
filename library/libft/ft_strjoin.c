/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 20:42:16 by yongmkim          #+#    #+#             */
/*   Updated: 2022/03/21 16:02:40 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	t_len;
	char	*temp;

	if (!s1 && !s2)
		return (NULL);
	t_len = ft_strlen(s1) + ft_strlen(s2);
	temp = ft_calloc(t_len + 1, sizeof(char));
	if (!temp)
		return (NULL);
	ft_strlcat(temp, s1, t_len + 1);
	ft_strlcat(temp, s2, t_len + 1);
	return (temp);
}
