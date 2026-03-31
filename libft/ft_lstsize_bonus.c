/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szine- <szine-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:14:46 by szine-            #+#    #+#             */
/*   Updated: 2023/11/30 15:27:47 by szine-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*temp;
	int		a;

	if (!lst)
		return (0);
	a = 0;
	temp = lst;
	while (temp->next != NULL)
	{
		temp = temp->next;
		a++;
	}
	return (a + 1);
}
