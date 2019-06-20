/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 13:38:26 by thaley            #+#    #+#             */
/*   Updated: 2019/06/20 13:56:52 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include <stdlib.h> //malloc, free, exit
# include <unistd.h> //access, write, read, getcwd, chdir, fork, execve
# include <fcntl.h> //open, 
# include <sys/stat.h> //stat, lstat, fstat
# include <sys/types.h> //read
# include <sys/uio.h> //read 
# include <sys/wait.h> //wait, waitpid, wait3, wait4
# include <signal.h> //signal, kill
# include <dirent.h> //opendir, readdir, closedir

#endif
