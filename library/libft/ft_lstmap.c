/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <codeyoma@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 16:27:01 by yongmkim          #+#    #+#             */
/*   Updated: 2021/06/03 21:27:43 by yongmkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*r_value;

	if (lst == NULL || f == NULL)
		return (NULL);
	r_value = NULL;
	while (lst)
	{
		temp = ft_lstnew((*f)(lst->content));
		if (!temp)
		{
			ft_lstclear(&r_value, del);
			return (NULL);
		}
		ft_lstadd_back(&r_value, temp);
		lst = lst->next;
	}
	return (r_value);
}
