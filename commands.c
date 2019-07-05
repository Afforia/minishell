/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 16:24:04 by thaley            #+#    #+#             */
/*   Updated: 2019/07/05 15:36:07 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void		exec_cmd(char *buil, char **cmd)
{
	pid_t	pid;

	pid = fork();
	signal(SIGINT, signal_handler_aux);
	if (pid == 0)
	{
		if (execve(buil, cmd, g_env) == -1)
		{
			ft_putendl("No such file or directory.");
			exit(0);
		}
	}
	else if (pid < 0)
	{
		ft_putendl("Fork faild to create a new process.");
		exit(0);
	}
	wait(&pid);
	if (buil)
		free(buil);
}

int			get_built(char **cmd, char **path_dir, int num)
{
	char	*buil;
	char	*path;

	if (num == -1)
		buil = ft_strdup(cmd[0]);
	else
	{
		path = ft_strjoin(path_dir[num], "/");
		buil = ft_strjoin(path, cmd[0]);
		free(path);
	}
	exec_cmd(buil, cmd);
	free_array(path_dir);
	return (1);
}

void		execute_cmds(char **cmds)
{
	char	**cmd;
	int		i;

	i = 0;
	while (cmds[i])
	{
		cmd = NULL;
		if (!(cmd = split_all(cmds[i])))
		{
			i++;
			continue ;
		}
		if (check_define(cmd))
			;
		if (check_dir(cmd[0]))
		{
			if (check_builtin(cmd) && check_utility(cmd))
				erroring(NULL, cmd[0], 3);
		}
		if (cmd)
			free_array(cmd);
		i++;
	}
	if (cmds)
		free_array(cmds);
}
