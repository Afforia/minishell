/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 13:38:26 by thaley            #+#    #+#             */
/*   Updated: 2019/06/28 20:23:21 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# define SPACES(x) (x == ' ' || x == '\t' || x == '\r' || x == '\f' || x == '\v')

# include <stdlib.h> //malloc, free, exit
# include <unistd.h> //access, write, read, getcwd, chdir, fork, execve
# include <fcntl.h> //open, 
# include <sys/stat.h> //stat, lstat, fstat
# include <sys/types.h> //read
# include <sys/uio.h> //read 
# include <sys/wait.h> //wait, waitpid, wait3, wait4
# include <signal.h> //signal, kill
# include <dirent.h> //opendir, readdir, closedir
# include "libft/libft.h"

# include <stdio.h>

char		**env;

void		free_array(char ***arr);
void		exit_shell(char **arr, int error);

void		print_welcome_msg();



char		**split_cmds(char *input);
char		**split_all(char *input);

void		get_built(char **cmd, int num);
void		execute_cmds(char **cmds);

void		change_pwd();
char		*parse_path(char *env, int	start);
int			env_start(char *search_string);

int			check_utility(char **cmd);
int			check_builtin(char **cmd);

void		change_dir(char **cmd);

void		rewrite_env(int pos, char *name, char *value);
int			set_env_aux(char *name, char *value, int overwrite);
int			set_env(char **cmd);

void		unset_env(char **cmd);

void		print_echo(char **cmd);
void		print_env(void);

char		*take_full_path(char *str);

void		erroring(char *cmd, char *str, int error);

char		*right_dir(char *dir);

#endif
