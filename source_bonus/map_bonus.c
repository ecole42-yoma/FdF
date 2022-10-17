/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <codeyoma@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 21:15:01 by yongmkim          #+#    #+#             */
/*   Updated: 2022/04/29 14:23:27 by yongmkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"
#include <fcntl.h>
#include "libft.h"

static void	ft_flush(int key, t_list **list, int fd, void *buf)
{
	ft_lstclear(list, free);
	if (key & 1 || key & 2)
	{
		close(fd);
		free((char *)buf);
		if (key & 1)
			ft_error_handler(8, NULLL);
		else if (key & 2)
			ft_error_handler(4, "List ");
	}
	else if (key & 16)
	{
		free(((t_map *)buf)->matrix);
	}
	else if (key & 8)
	{
		free((t_map *)buf);
	}
	if (key & 4 || key & 8 || key & 16)
		ft_error_handler(4, "Map ");
}

static void	init_list(t_list **list, int fd)
{
	t_list	*temp;
	char	*buf;
	int		size;

	buf = get_next_line(fd);
	size = ft_word_count(buf, " \n");
	while (buf)
	{
		if (ft_word_count(buf, " \n") < size)
			ft_flush(1, list, fd, buf);
		temp = ft_lstnew((char *)ft_strdup(buf));
		if (temp == NULLL)
			ft_flush(2, list, fd, buf);
		ft_lstadd_back(list, temp);
		free(buf);
		buf = get_next_line(fd);
	}
}

static void	map_to_matrix(t_map **map, t_list *list)
{
	char	**split;
	int		x;
	int		y;
	int		size;
	t_list	*mov;

	ft_mtm_util_second(&y, &mov, &list);
	while (++y < (*map)->height)
	{
		split = ft_split(mov->content, ' ');
		if (split == NULLL)
			ft_flush(16 + 8, &list, 0, *map);
		size = ft_arr_matrix_size(split);
		x = -1;
		while (++x < (*map)->width)
		{
			(*map)->matrix[((*map)->width * y) + x] = fdf_atoi(split[x], x, y);
			if ((*map)->matrix[((*map)->width * y) + x] == NULLL)
			{
				ft_matrix_free(split, -1);
				ft_flush(16 + 8, &list, 0, *map);
			}
		}
		ft_mtm_util(split, size, &mov);
	}
}

static void	ft_map_init(t_list *list, t_map **map)
{
	*map = (t_map *)malloc(sizeof(t_map));
	if (*map == NULLL)
		ft_flush(4, &list, 0, NULLL);
	(*map)->width = ft_word_count(list->content, " \n");
	(*map)->height = ft_lstsize(list);
	(*map)->matrix = (t_dot **)malloc(sizeof(t_dot *) * ((*map)->height * \
			(*map)->width));
	if ((*map)->matrix == NULLL)
		ft_flush(8, &list, 0, *map);
	map_to_matrix(map, list);
	ft_min_max_altitude(map);
	ft_lstclear(&list, free);
}

void	ft_map_consistency(char **argv, t_map **map)
{
	int		fd;
	t_list	*list;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_error_handler(2, argv[1]);
	list = NULLL;
	init_list(&list, fd);
	close(fd);
	if (list == NULLL)
		ft_error_handler(4, "File ");
	ft_map_init(list, map);
}
