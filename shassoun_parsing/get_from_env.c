/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_from_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shassoun <shassoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 14:39:15 by shassoun          #+#    #+#             */
/*   Updated: 2024/12/26 20:19:08 by shassoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*one_space(char *str1)
{
	char	**res;
	int		i;

	i = 1;
	res = NULL;
	res = ft_split(str1, ' ');
	free(str1);
	str1 = NULL;
	if (res[0])
		str1 = res[0];
	while (res[i] != NULL)
	{
		str1 = ft_strjoin2(str1, ft_strdup(" "));
		str1 = ft_strjoin2(str1, res[i]);
		i++;
	}
	free(res);
	return (str1);
}

char	*get_from_my_env(char *str, t_redi *env, char c)
{
	char	*str1;
	int		i;

	(void)c;
	i = 0;
	str1 = NULL;
	while (env != NULL)
	{
		i = 0;
		while (env->file[i] && str[i] && env->file[i] == str[i])
			i++;
		if (!str[i] && env->file[i] == '=')
		{
			str1 = ft_strdup(env->file + (i + 1));
			if ((ft_strchr(str1, ' ') != NULL) && c != '\"')
			{
				str1 = one_space(str1);
			}
			return (str1);
		}
		env = env->next;
	}
	return (NULL);
}

void	get_last_env(t_redi *tocken, t_redi *env)
{
	t_redi	*temp;

	temp = tocken;
	if (env == NULL)
		return ;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	free(env->file);
	env->file = ft_strdup(temp->file);
}
