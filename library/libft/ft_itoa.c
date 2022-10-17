/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <codeyoma@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 00:13:52 by yongmkim          #+#    #+#             */
/*   Updated: 2022/04/21 20:55:20 by yongmkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_getsize(int nbr)
{
	size_t	size;

	size = 0;
	if (nbr <= 0)
		size = 1;
	while (nbr)
	{
		nbr /= 10;
		size++;
	}
	return (size);
}

static void	ft_numbersplit(char *temp, size_t len, int n)
{
	size_t	remainder;

	if (n < 0)
	{
		n *= -1;
		temp[0] = '-';
	}
	while (len)
	{
		remainder = n % 10;
		n /= 10;
		if (temp[0] == '-' && len == 1)
			break ;
		temp[len - 1] = "0123456789"[remainder];
		len--;
	}
	return ;
}

char	*ft_itoa(int n)
{
	size_t	len;
	char	*temp;

	if (n == MIN_INT)
		return (ft_strdup("-2147483648"));
	len = ft_getsize(n);
	temp = ft_calloc(len + 1, sizeof(char));
	if (!temp)
		return (NULL);
	temp[len] = '\0';
	ft_numbersplit(temp, len, n);
	return (temp);
}
