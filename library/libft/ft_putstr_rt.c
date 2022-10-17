/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_rt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 21:27:49 by yongmkim          #+#    #+#             */
/*   Updated: 2022/03/19 11:08:23 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_rt(char *str)
{
	if (!str)
		return (ft_putstr_rt("(null)"));
	return (write(1, str, ft_strlen(str)));
}
