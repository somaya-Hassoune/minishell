/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szine- <szine-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 05:53:46 by szine-            #+#    #+#             */
/*   Updated: 2024/12/28 11:09:18 by szine-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	dup_the_out(t_redi *output)
{
	t_redi	*temp;
	int		fd;

	fd = 0;
	if (___chkst(&temp, &output) == 1)
		return (0);
	while (temp)
	{
		if (temp->is_the == 1337)
			return (eprintf("ambiguous redirect\n", temp->file), -1);
		if (temp->next != NULL)
		{
			fd = open(temp->file, O_WRONLY | O_TRUNC | O_CREAT, 0666);
			if (fd == -1)
				return (eprintf("bash : %s ", temp->file), perror(""), -1);
		}
		else
			fd = for_in(temp);
		if (fd == -1)
			return (-1);
		else
			close(fd);
		temp = temp->next;
	}
	return (fd);
}

int	trait_the_herr(int herr, char *file)
{
	char	*str;
	int		fd;

	str = ft_strjoin2(ft_strdup("/tmp/"), ft_itoa(herr));
	fd = open(str, O_CREAT | O_RDONLY);
	if (fd == -1)
		return (eprintf("bash : %s", file), perror(""), free(str), -1);
	return (dup2(fd, 0), close(fd), free(str), fd);
}

int	dup_the_in(t_redi *input, int herr)
{
	int		fd;
	t_redi	*temp;

	temp = input;
	if (input == NULL)
		return (0);
	while (temp)
	{
		if (temp->is_the == 1337)
			return (eprintf("bash: %s : ambiguous redirect\n", temp->file), -1);
		if (temp->mode == '<')
		{
			fd = open(temp->file, O_RDONLY);
			if (fd == -1)
				return (eprintf("bash : %s", temp->file), perror(""), -1);
			if (temp->next == NULL)
				dup2(fd, 0);
			close(fd);
		}
		else if (temp->next == NULL && herr != 0)
			return (trait_the_herr(herr, temp->file));
		temp = temp->next;
	}
	return (fd);
}

void	free_dbl(char **res)
{
	int	i;

	i = 0;
	while (res[i] != NULL)
	{
		free(res[i]);
		i++;
	}
	free(res);
}

char	**get_itt(t_redi *temp, char **str)
{
	char	**res;
	int		i;
	int		j;

	res = NULL;
	i = 0;
	while (temp)
	{
		if (temp->is_the == 42)
			res = ft_split(temp->file, ' ');
		if ((res != NULL) && (temp->is_the == 42))
		{
			j = 0;
			while (res[j] != NULL)
				str[i++] = res[j++];
			free(res);
		}
		else
			str[i++] = ft_strdup(temp->file);
		temp = temp->next;
	}
	str[i] = NULL;
	return (str);
}
