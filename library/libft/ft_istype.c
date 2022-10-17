/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_istype.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 21:27:52 by yongmkim          #+#    #+#             */
/*   Updated: 2022/03/01 21:28:41 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_istype(char c)
{
	char	*type;

	if (!c)
		return (0);
	type = "cspdiuxX%";
	while (*type)
	{
		if (c == *type)
			return (*type);
		type++;
	}
	return (0);
}
