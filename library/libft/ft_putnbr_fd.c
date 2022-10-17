/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 01:50:03 by yongmkim          #+#    #+#             */
/*   Updated: 2022/04/21 20:56:14 by yongmkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_nbr_width(ssize_t n)
{
	size_t	len;

	if (n == 0)
		return (1);
	if (n == MIN_INT)
		return (11);
	else if (n < 0)
	{
		len = 1;
		n *= -1;
	}
	else
		len = 0;
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static int	ft_nbr_size(int n)
{
	int	len;

	if (n == 0)
		return (1);
	if (n == MIN_INT)
		return (11);
	else if (n < 0)
	{
		len = 1;
		n *= -1;
	}
	else
		len = 0;
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static int	ft_iter_div(int *n, int pos)
{
	int	temp;
	int	front_nbr;

	temp = 1;
	while (pos > 1)
	{
		temp *= 10;
		pos--;
	}
	front_nbr = *n / temp;
	*n -= (temp * front_nbr);
	return (front_nbr);
}

void	ft_putnbr_fd(int n, int fd)
{
	int	cnt;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		if (n == MIN_INT)
		{
			ft_putstr_fd("2147483648", fd);
			return ;
		}
		n *= -1;
	}
	cnt = ft_nbr_size(n);
	while (cnt > 0)
	{
		ft_putchar_fd("0123456789"[ft_iter_div(&n, cnt)], fd);
		cnt--;
	}
}
