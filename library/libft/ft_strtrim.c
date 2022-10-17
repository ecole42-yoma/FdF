/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <codeyoma@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 21:41:13 by yongmkim          #+#    #+#             */
/*   Updated: 2021/06/03 18:47:58 by yongmkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	front;
	size_t	rear;
	char	*temp;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	front = 0;
	rear = ft_strlen(s1);
	while (s1[front] && ft_strchr(set, s1[front]))
		front++;
	while (s1[rear - 1] && ft_strchr(set, s1[rear - 1]) && rear > front)
		rear--;
	temp = ft_calloc((rear - front + 1), sizeof(char));
	if (!temp)
		return (NULL);
	ft_strlcpy(temp, s1 + front, (rear - front + 1));
	return (temp);
}
