/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szine- <szine-@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 15:53:27 by shassoun          #+#    #+#             */
/*   Updated: 2024/12/27 10:36:34 by szine-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_lexer(t_redi *tocken)
{
	t_redi	*sa;

	sa = tocken;
	if (many_herdoc(tocken) == 1)
		return (free_liste(tocken), 1);
	if ((sa->mode != 0 && sa->next && sa->next->mode != 0) || sa->mode == '|')
		return (free_liste(tocken), eprintf("syntaxe error\n"), 1);
	while (sa->next)
	{
		if ((sa->mode != 0 && sa->next && sa->next->mode != 0))
		{
			if (!(sa->mode == '|' && (sa->next->mode == '<'
						|| sa->next->mode == '>' || sa->next->mode == '>' + 1
						|| sa->next->mode == '<' + 1)))
				return (free_liste(tocken), eprintf("syntaxe error\n"), 1);
			if (sa->next->next && sa->next->next->mode != 0)
				return (free_liste(tocken), eprintf("syntaxe error\n"), 1);
		}
		sa = sa->next;
	}
	if (sa->mode != 0)
		return (free_liste(tocken), eprintf("syntaxe error\n"), 1);
	return (0);
}

t_pipe	*build_all(t_redi *tocken)
{
	t_pipe	*all;
	t_redi	*temp;
	t_pipe	*pr;

	all = NULL;
	temp = tocken;
	pr = NULL;
	while (temp)
	{
		pr = malloc(sizeof(t_pipe));
		pr->input = NULL;
		pr->output = NULL;
		pr->commd = NULL;
		pr->next = NULL;
		while (temp && temp->mode != '|')
			new_pipe_node(&temp, pr);
		add_pipe_node(&all, pr, &temp);
	}
	return (all);
}

int	_suit_main(t_redi *tocken, char *command, int *status, t_redi *env)
{
	if (ft_lexer(tocken) == 1)
	{
		free(command);
		*status = 2;
		return (1);
	}
	get_last_env(tocken, env);
	free(command);
	return (0);
}

void	expand_and_set(t_redi *nt, int *status, t_redi *env)
{
	char	*str_;

	str_ = nt->file;
	nt->file = ft_expand(nt->file, status, env);
	if (nt->file != str_)
		nt->is_the = 42;
	if (nt->file && (nt->file)[0] == '\0')
		nt->is_the = 1337;
}

t_pipe	*uusplit(char *command, int *status, t_redi *env)
{
	t_redi	*tocken;
	t_redi	*nt;
	int		fg;
	char	*str_;

	str_ = NULL;
	tocken = ft_tocken(command, status);
	check_empty(tocken);
	nt = tocken;
	fg = 0;
	str_ = NULL;
	if (tocken == NULL)
		return (NULL);
	while (nt)
	{
		if (fg == 1)
			fg = 0;
		else if (ft_strchr(nt->file, '$') != NULL && env != NULL)
			expand_and_set(nt, status, env);
		check_herdoc(nt, &fg);
		nt = nt->next;
	}
	if (_suit_main(tocken, command, status, env) == 1)
		return (NULL);
	return (build_all(tocken));
}
