/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <codeyoma@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 11:00:13 by yongmkim          #+#    #+#             */
/*   Updated: 2022/04/29 03:09:45 by yongmkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isnbr(char str, int base)
{
	char	*nbr;
	int		cnt;

	if (str == '\0')
		return (0);
	nbr = "0123456789abcdef";
	cnt = 1;
	while (*nbr && cnt <= base)
	{
		if (*nbr == ft_tolower(str))
			return (cnt);
		++nbr;
		++cnt;
	}
	return (0);
}

int	ft_isspace(int c)
{
	char	*space;

	space = "\t\n\v\f\r ";
	while (*space)
	{
		if (c == *space)
			return (TRUE);
		space++;
	}
	return (FALSE);
}

static int	ft_sign_base_pro(int *sign, char **str, int base)
{
	if (**str == '-')
	{
		if (base != 16)
		{
			*sign = -1;
			(*str)++;
		}
	}
	if (base == 16)
	{
		if (**str == '0')
		{
			(*str)++;
			if (**str == 'x')
				(*str)++;
			else
				return (1);
		}
		else
			return (1);
	}
	return (0);
}

int	ft_atoi_base(char *str, int base)
{
	int	sum;
	int	sign;
	int	temp;

	if (str == NULLL || *str == '\0')
		return (0);
	sum = 0;
	sign = 1;
	while (ft_isspace(*str) && *str != '\0')
		str++;
	temp = ft_sign_base_pro(&sign, &str, base);
	if (temp == 1)
		return (ft_atoi_base(str, 10));
	while (ft_isnbr(*str, base))
	{
		sum = (sum * base) + (ft_isnbr(*str, base) - 1);
		str++;
	}
	if (*str == 'x' && sum % 10 == 0)
		return ((sum / 10) * sign);
	return (sum * sign);
}

int	ft_atoi(const char *str)
{
	unsigned long long	sum;
	int					sign;

	sum = 0;
	sign = 1;
	while (ft_isspace(*str) && (*str != 0))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		sum = (sum * 10) + (*str - '0');
		str++;
	}
	if (sum > MAX_INT && sign == 1)
		return (-1);
	if (sum - 1 > MAX_INT && sign == -1)
		return (0);
	return (sign * sum);
}
