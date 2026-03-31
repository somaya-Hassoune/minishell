/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szine- <szine-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 15:12:43 by shassoun          #+#    #+#             */
/*   Updated: 2024/12/27 10:24:16 by szine-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*set_i(char *command, int *i)
{
	(*i)++;
	while (command[*i] && command[*i] != '\"' && command[*i] != '$'
		&& command[*i] != '\'' && command[*i] != ' ' && command[*i] != '\n'
		&& is_special(command[*i]) == 0)
		(*i)++;
	return (strncp_yy(command + (*i), ft_strlen(command) - (*i)));
}

char	*get_content(char c, int *status, t_redi *env)
{
	char	*content;

	content = NULL;
	(void)status;
	if (c == '?')
		content = ft_itoa(*status);
	else if (c == '_')
		content = ft_strdup(env->file);
	return (content);
}

char	*expend_it1(char *command, int *i, int *status, t_redi *env)
{
	char	*content;
	char	*str1;
	char	*to_replace;
	char	*str3;
	int		k;

	content = NULL;
	to_replace = NULL;
	k = *i;
	if (command[*i + 1] && (command[*i + 1] == '?' || command[*i + 1] == '_'))
	{
		(*i) = (*i) + 1;
		str3 = strncp_yy(command + (*i) + 1, strlen(command) - (*i) - 1);
		content = get_content(command[*i], status, env);
	}
	else
	{
		str3 = set_i(command, i);
		to_replace = strncp_yy(command + k, (*i) - k);
		content = get_from_my_env(to_replace + 1, env, '\"');
	}
	str1 = strncp_yy(command, k);
	free(command);
	command = strjoine(str1, content, str3);
	return (free(to_replace), free(str1), free(str3), free(content), command);
}

char	*expend_it0(char *command, int *i, int *status, t_redi *env)
{
	char	*content;
	char	*str1;
	char	*to_replace;
	char	*str3;
	int		k;

	content = NULL;
	to_replace = NULL;
	k = *i;
	if (command[*i + 1] && (command[*i + 1] == '?' || command[*i + 1] == '_'))
	{
		(*i) = (*i) + 1;
		str3 = strncp_yy(command + (*i) + 1, strlen(command) - (*i) - 1);
		content = get_content(command[*i], status, env);
	}
	else
	{
		str3 = set_i(command, i);
		to_replace = strncp_yy(command + k, (*i) - k);
		content = get_from_my_env(to_replace + 1, env, (char)0);
	}
	str1 = strncp_yy(command, k);
	free(command);
	command = strjoine(str1, content, str3);
	return (free(to_replace), free(str1), free(str3), free(content), command);
}

char	*ft_expand(char *co, int *status, t_redi *env)
{
	int		i;
	int		flag;
	char	c;

	i = 0;
	flag = 0;
	c = 0;
	while (i < (int)ft_strlen(co) && co[i])
	{
		__is__(co, i, &c, &flag);
		if ((i < (int)ft_strlen(co)) && co[i] == '$' && co[i + 1] && co[i + 1]
			!= ' ' && co[i + 1] != '\'' && co[i + 1] != '\"' && flag != 1)
		{
			if (c == '\"')
				co = expend_it1(co, &i, status, env);
			else
				co = expend_it0(co, &i, status, env);
			if (co && co[0] == '\0')
				break ;
		}
		else
			i++;
	}
	return (co);
}
