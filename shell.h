/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 13:38:26 by thaley            #+#    #+#             */
/*   Updated: 2019/07/03 18:18:29 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# define SPACES(x) (x == ' ' || x == '\t' || x == '\f' || x == '\v')
# define SPES_CHAR(x) (x == '@' || x == '#' || x == '%' || x == '^')
# define MORE_SPES_CHAR(x) (x == '*' || x == '"' || x == '\'')

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/wait.h>
# include <signal.h>
# include <dirent.h>
# include "libft/libft.h"

# include <stdio.h>

char		**g_env;

void		signal_handler(int sign);

void		free_array(char **arr);
void		exit_shell(char **arr, int error);

void		print_welcome_msg(void);

char		*ft_realloc(char *str, int i);

char		**split_cmds(char *input);
char		**split_all(char *input);

char		*take_input(void);

int			get_built(char **cmd, char **path_dir, int num);
void		execute_cmds(char **cmds);

void		change_pwd();
char		*parse_path(char *env, int	start);
int			env_start(char *search_string);

int			check_utility(char **cmd);
int			check_builtin(char **cmd);
int			count_dir(int pos);

void		change_dir(char **cmd);
char		**parse_path_dir(void);

void		rewrite_env(int pos, char *name, char *value);
int			set_env_aux(char *name, char *value, int overwrite);
int			set_env(char **cmd);

void		unset_env(char **cmd);

void		print_env(void);
void		print_echo(char **cmd, int start, int end, int flag);

char		*take_full_path(char *str);

void		erroring(char *cmd, char *str, int error);

char		*right_dir(char *dir);

void		echo_builtin(char **cmd);

int			check_define(char **cmd);
int			check_dir(char *cmd);
char		*right_dir(char *dir);
int			count_cmds(char *str);
int			word_len(char *input, int i);
int			count_words(char *input);

#endif
