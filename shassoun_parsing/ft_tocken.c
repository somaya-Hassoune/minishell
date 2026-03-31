/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tocken.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shassoun <shassoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 18:16:56 by shassoun          #+#    #+#             */
/*   Updated: 2024/12/26 23:18:42 by shassoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	copy_operator(char *operator, int *i, int mode, t_redi **tocken)
{
	t_redi	*temp;

	temp = NULL;
	temp = new_node(ft_strdup(operator), mode);
	add_node(tocken, temp);
	if (mode == '<' + 1 || mode == '>' + 1)
		(*i) = (*i) + 2;
	else
		(*i)++;
}

int	copy_word(char *command, int *i, t_redi **tocken, int *status)
{
	t_redi	*temp;
	char	c;
	int		fg;
	int		k;

	k = *i;
	fg = 0;
	temp = NULL;
	while ((command[k] && fg == 1) || (command[k] && command[k] != '>'
			&& command[k] != '|' && command[k] != '<' && command[k] != ' '))
	{
		if (fg == 0 && (command[k] == '\'' || command[k] == '\"'))
			__check_set(command, &c, k, &fg);
		else if (fg == 1 && command[k] == c)
			fg = 0;
		k++;
	}
	if (check_quot(fg, tocken, status) == 1)
		return (1);
	if (k != *i)
		temp = new_node(strncp_yy(command + (*i), k - (*i)), 0);
	if (k != *i)
		add_node(tocken, temp);
	*i = k;
	return (0);
}

t_redi	*ft_tocken(char *command, int *status)
{
	int		i;
	t_redi	*tocken;

	i = 0;
	tocken = NULL;
	while (command[i])
	{
		if (command[i + 1] && command[i] == '>' && command[i + 1] == '>')
			copy_operator(">>", &i, '>' + 1, &tocken);
		else if (command[i + 1] && command[i] == '<' && command[i + 1] == '<')
			copy_operator("<<", &i, '<' + 1, &tocken);
		else if (command[i] == '<')
			copy_operator("<", &i, '<', &tocken);
		else if (command[i] == '>')
			copy_operator(">", &i, '>', &tocken);
		else if (command[i] == '|')
			copy_operator("|", &i, '|', &tocken);
		else if (command[i] == ' ')
			i++;
		else if (copy_word(command, &i, &tocken, status) == 1)
			return (NULL);
	}
	return (tocken);
}
