/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <codeyoma@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 22:27:17 by yongmkim          #+#    #+#             */
/*   Updated: 2022/04/24 23:21:44 by yongmkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_small(int x, int y)
{
	if (x < y)
		return (1);
	return (-1);
}

int	ft_min(int x, int y)
{
	if (x > y)
		return (y);
	return (x);
}

int	ft_max(int x, int y)
{
	if (x < y)
		return (y);
	return (x);
}

int	ft_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}
