/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 13:38:26 by thaley            #+#    #+#             */
/*   Updated: 2019/06/25 20:20:56 by thaley           ###   ########.fr       */
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

void		get_built(char **cmd);
void		execute_cmds(char **cmds);

void		new_pwd(char *path);
char		*parse_path(char *env, int	start);
int			env_start(char *search_string);

int			check_builtin(char **cmd);

void		change_dir(char **cmd);


#endif
