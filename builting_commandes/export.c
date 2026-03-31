/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szine- <szine-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 21:29:07 by szine-            #+#    #+#             */
/*   Updated: 2024/12/28 09:34:48 by szine-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_redi	*export_this(t_redi *env, char *str, int *i)
{
	t_redi	*tempo;

	tempo = NULL;
	while (str[*i] && env)
	{
		*i = 0;
		while ((env->file[*i] && str[*i] && env->file[*i] == str[*i])
			|| (str[*i] == '+' && env->file[*i] == '='))
		{
			if (str[(*i)] == '+' && str[(*i) + 1] == '=')
			{
				tempo = env;
				return (tempo);
			}
			else if (str[(*i)] == '=')
			{
				tempo = env;
				return (tempo);
			}
			(*i)++;
		}
		env = env->next;
	}
	return (tempo);
}

int	error_handling(char *str, int *mode)
{
	int	i;

	i = 0;
	if (str[0] == '=' || (str[0] >= '0' && str[0] <= '9'))
		return (eprintf("bash: export: `%s': not a valid identifier\n", str),
			1);
	while (str[i] && str[i] != '=')
	{
		if (str[i] == '-' || (str[i] == '+' && str[i + 1] != '='))
			return (eprintf("bash: export: `%s': not a valid identifier\n",
					str), 1);
		i++;
	}
	if (str[i] == '\0')
		*mode = 0;
	else
		*mode = 1;
	if ((i > 0 && str[i] && str[i] == '=' && str[i - 1] == ' '))
		return (eprintf("bash: export: `%s': not a valid identifier\n", str),
			1);
	return (0);
}

int	export_one(t_redi *command, t_redi *env)
{
	int		mode;
	int		i;
	t_redi	*tempo;

	i = 0;
	tempo = NULL;
	if (error_handling(command->next->file, &mode) == 1)
		return (1);
	tempo = export_this(env, command->next->file, &i);
	if (tempo != NULL)
	{
		if ((command->next->file)[i] == '=')
			free(tempo->file);
		if ((command->next->file)[i] == '=')
			tempo->file = ft_strdup(command->next->file);
		else if ((command->next->file)[i] == '+')
			tempo->file = ft_strjoin2(tempo->file,
					ft_strdup(command->next->file) + (i + 2));
	}
	else
	{
		tempo = new_node(ft_strdup(command->next->file), mode);
		add_node(&env, tempo);
	}
	return (0);
}

void	export_no_argument(t_redi *env)
{
	int	i;
	int	flag;

	i = 0;
	env = env->next;
	while (env)
	{
		flag = 0;
		i = 0;
		write(1, "declare -x ", 11);
		while (env->file[i])
		{
			write(1, &env->file[i], 1);
			if (flag == 0 && env->file[i] == '=')
			{
				write(1, "\"", 1);
				flag = 1;
			}
			i++;
		}
		if (flag == 1)
			write(1, "\"", 1);
		write(1, "\n", 1);
		env = env->next;
	}
}

void	export(t_redi *command, t_redi *env, int *status)
{
	*status = 0;
	if (command->next == NULL)
	{
		export_no_argument(env->next);
		return ;
	}
	while (command->next != NULL)
	{
		if (export_one(command, env->next) == 1)
		{
			*status = 1;
		}
		command = command->next;
	}
}
