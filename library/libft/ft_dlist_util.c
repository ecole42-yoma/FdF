/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:14:42 by yongmkim          #+#    #+#             */
/*   Updated: 2022/03/13 20:50:29 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*ft_dlist_find(t_dlist *lst, ssize_t value)
{
	while (lst)
	{
		if (value == lst->value)
			return (lst);
		lst = lst->next;
	}
	return (NULLL);
}

t_dlist	*ft_dlist_pick(t_dlist **lst, ssize_t value)
{
	t_dlist	*temp;

	temp = ft_dlist_find(*lst, value);
	if (temp)
	{
		if (temp->pre)
			temp->pre->next = temp->next;
		if (temp->next)
			temp->next->pre = temp->pre;
		if (temp->pre == NULLL)
			*lst = temp->next;
		temp->next = NULLL;
		temp->pre = NULLL;
	}
	return (temp);
}

t_dlist	*ft_dlist_del(t_dlist **lst, ssize_t value, int key)
{
	t_dlist	*temp;

	if (key & FIND_DEL)
	{
		temp = ft_dlist_pick(lst, value);
		if (temp == *lst)
			*lst = NULLL;
		free(temp);
		return ((void *)SUCCESS);
	}
	if (key & JUST_DEL && value == 0)
	{
		if ((*lst)->pre)
			(*lst)->pre->next = (*lst)->next;
		if ((*lst)->next)
			(*lst)->next->pre = (*lst)->pre;
		if (key & JUST_DEL)
			free(*lst);
		*lst = NULLL;
		return ((void *)SUCCESS);
	}
	return ((void *)ERROR);
}

void	ft_dlist_del_all(t_dlist **head)
{
	t_dlist	*temp;

	while (*head)
	{
		temp = (*head)->next;
		ft_dlist_del(head, 0, JUST_DEL);
		*head = temp;
	}
	*head = NULLL;
}
