/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szine- <szine-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 20:44:33 by szine-            #+#    #+#             */
/*   Updated: 2023/11/30 17:46:47 by szine-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*new_node;

	if (!lst || !del)
		return ;
	temp = *lst;
	while (temp)
	{
		new_node = temp->next;
		del(temp->content);
		free(temp);
		temp = new_node;
	}
	*lst = NULL;
}
