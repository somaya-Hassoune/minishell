/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szine- <szine-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:01:11 by szine-            #+#    #+#             */
/*   Updated: 2023/11/30 15:26:45 by szine-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*temp;
	void	*p;

	result = NULL;
	temp = NULL;
	if (!lst || !f || !del)
	{
		return (NULL);
	}
	while (lst)
	{
		p = f(lst->content);
		temp = ft_lstnew(p);
		if (!temp)
		{
			free(p);
			ft_lstclear(&result, del);
			return (NULL);
		}
		ft_lstadd_back(&result, temp);
		lst = lst->next;
		temp = temp->next;
	}
	return (result);
}
