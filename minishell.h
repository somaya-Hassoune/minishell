/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szine- <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 22:15:37 by szine-            #+#    #+#             */
/*   Updated: 2024/12/28 22:15:43 by szine-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <fcntl.h>
# include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>
# include <wait.h>

extern int				g_status;

# define PATH_MAX 4096

typedef struct redirection
{
	char				*file;
	int					mode;
	int					is_the;
	struct redirection	*next;

}						t_redi;

typedef struct pipe
{
	t_redi				*commd;
	t_redi				*input;
	t_redi				*output;
	struct pipe			*next;
}						t_pipe;

typedef struct tock
{
	char				**arg;
	int					*type;
}						t_tockens;
typedef struct tt
{
	t_pipe				*current;
	t_pipe				*all;
	t_redi				*env;
	int					pid;

}						t_tt;

int						ft_cd(t_redi *command, t_redi *env, int *status);
int						eprintf(const char *format, ...);
void					ft_echo(t_redi *command, int *status);
int						export_one(t_redi *command, t_redi *env);
size_t					ft_strlen(const char *str);
t_redi					*new_node(char *str, int flag);
void					add_node(t_redi **list, t_redi *node);
t_pipe					*b_node(t_tockens *tockens, int *i);
void					*ft_calloc(size_t numelement, size_t elementsize);
char					*find_path(t_redi *command, t_redi *env);
char					**convert(t_redi *command);
void					ft_env(t_redi *env, int *status);
void					*ft_memmove(void *dest, const void *src, size_t n);
int						the_pipe(char *str, int *status, t_redi *env);
char					*ft_expand(char *command, int *status, t_redi *env);
void					ft_pwd(void);
int						ft_strcmp(char *str1, char *str2);
void					export(t_redi *command, t_redi *env, int *status);
char					*ft_itoa(int n);
char					*is_exist(void);
char					*ft_strjoin1(char *s1, char *s2);
int						ft_herdoc(int *tab, t_pipe *all, t_redi *env,
							int *status);
int						ft_atoi(const char *str);
char					*ft_strchr(const char *s, int c);
int						ft_isdigit(int c);
int						ft_exit(t_pipe *all, int *status, t_redi *env);
int						ft_is_num(char *str);
int						pair_qot(char *str);
t_pipe					*uusplit(char *command, int *status, t_redi *env);
char					*ft_strdup(const char *str);
char					*get_from_my_env(char *str, t_redi *env, char c);
t_redi					*gettheenv(void);
int						build_in(t_pipe *current, t_redi *env, int *status,
							int flag);
char					**ft_split(char const *s, char c);
void					unset(t_redi **env, t_redi *command, int *status);
void					freetpipe(t_pipe *all);
void					free_liste(t_redi *li);
int						is_building(t_pipe *current, t_redi *env);
long					ft_atoi_(char *str);
char					*ft_strdup(const char *str);
char					*get_env(t_redi *env, char *str);
char					**ft_split(char const *s, char c);
void					free_dbl(char **res);
char					*ft_strjoin2(char *s1, char *s2);
char					*ft_strtrim(char const *s1, char const *set);
void					__is__(char *command, int i, char *c, int *flag);
int						is_special(char c);
char					*one_space(char *str1);
char					*strncp_yy(char *src, int n);
char					*strjoine(char *str1, char *str2, char *str3);
int						check_quot(int fg, t_redi **tocken, int *status);
void					__check_set(char *command, char *c, int k, int *fg);
int						many_herdoc(t_redi *tocken);
void					check_herdoc(t_redi *nty, int *fg);
void					new_pipe_node(t_redi **temp, t_pipe *pr);
void					add_pipe_node(t_pipe **all, t_pipe *pr, t_redi **temp);
t_redi					*ft_tocken(char *command, int *status);
int						count_words(char const *s, char c);
int						is_directory(char *path);
int						chk_ctrld(char *the_input, char *name_of_file);
int						if_last(char *name_of_file);
int						is_that_shlvl(char *envi);
int						first_command(t_pipe *current, int *fd, int *old_end,
							int nameHerdocfile);
int						middle_command(t_pipe *current, int *fd, int *old_end,
							int nameHerdocfile);
int						last_command(t_pipe *current, int *fd, int *old_end,
							int nameHerdocfile);
void					wait_and_set(int *status, int pid);
void					delete_herr_fil(int *tab);
int						dup_the_out(t_redi *output);
int						trait_the_herr(int herr, char *file);
int						dup_the_in(t_redi *input, int herr);
void					free_dbl(char **res);
char					**get_itt(t_redi *temp, char **str);
char					**convert(t_redi *command);
int						check_build(t_pipe *current, int *tab, t_redi *env,
							int *status);
void					close_2(int fd1, int fd2);
void					if_exit(int a);
int						___chkst(t_redi **temp, t_redi **output);
int						for_in(t_redi *temp);
void					inisialize_tab(int *tab);
void					handherr(int sig);
char					*get_next_line(int fd);
void					ddd(int sig);
void					_set0(int *i, int *k);
void					fd_old_new(int *old_end, int *fd, int *index);
void					handle_sigint2(int sig);
void					handle_sigint(int sig);
void					handle_sigquit(int sig);
void					get_last_env(t_redi *tocken, t_redi *env);
void					check_empty(t_redi *tocken);
int						one_herdoc(int *herr, t_redi *temp, t_redi *env,
							int *status);
void					is_empty(t_redi *tocken);
int						put_in_file(char *limit, t_redi *env, int *status,
							int is_last);
int						check_error_home(char *str, int *status);
int						ft_cd_home(t_redi *command, t_redi *env, int *status,
							char *home);
void					not_exec(char *str);

#endif
