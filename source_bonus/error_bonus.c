/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <codeyoma@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 21:53:11 by yongmkim          #+#    #+#             */
/*   Updated: 2022/04/23 16:04:37 by yongmkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_memflush(void **target)
{
	free(*target);
	*target = NULLL;
}

void	ft_error_handler(int key, char *str)
{
	if (key & 1)
		ft_putstr_fd("Usage : ./fdf <filename> [ case_size z_size ]\n", \
				STD_ERR);
	else if (key & 2)
	{
		ft_putstr_fd("No file ", STD_ERR);
		ft_putstr_fd(str, STD_ERR);
		ft_putchar_fd('\n', STD_ERR);
	}
	else if (key & 4)
		perror(str);
	else if (key & 8)
		ft_putstr_fd("Found wrong line length. Exiting.\n", STD_ERR);
	if (key == 0)
		return ;
	exit(1);
}

void	ft_argument_consistency(int argc)
{
	if (argc <= 1 || argc == 3 || argc > 4)
		ft_error_handler(1, NULLL);
}
