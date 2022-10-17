/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <codeyoma@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 00:27:48 by yongmkim          #+#    #+#             */
/*   Updated: 2022/04/26 21:22:27 by yongmkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_samesame(char one, char *sep)
{
	int	size;

	if (sep == NULLL)
		return (1);
	size = ft_strlen(sep);
	while (size)
	{
		if (one == *sep)
			return (0);
		sep++;
		--size;
	}
	return (1);
}

int	ft_word_count(char *str, char *sep)
{
	int	cnt;
	int	flag;

	if (str == NULLL)
		return (0);
	cnt = 0;
	flag = 0;
	while (*str)
	{
		if (ft_is_samesame(*str, sep))
		{
			if (flag == 0)
			{
				flag = 1;
				++cnt;
			}
		}
		else if (flag == 1)
			flag = 0;
		str++;
	}
	return (cnt);
}
