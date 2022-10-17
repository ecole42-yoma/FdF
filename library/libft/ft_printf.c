/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 17:29:35 by yongmkim          #+#    #+#             */
/*   Updated: 2022/03/09 20:15:58 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_pf_parse(va_list ap, char *str)
{
	int	rt_len;
	int	temp;

	rt_len = 0;
	while (*str)
	{
		temp = 0;
		if (*str == '%')
		{
			if (*(str + 1))
			{
				temp += ft_pf_process(ap, ft_istype(*(++str)));
				if (!temp && !ft_istype(*str))
					str--;
			}
			rt_len += temp;
		}
		else
			rt_len += write(1, str, 1);
		str++;
	}
	return (rt_len);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		rt_len;

	va_start(ap, str);
	rt_len = ft_pf_parse(ap, (char *)str);
	va_end(ap);
	return (rt_len);
}
