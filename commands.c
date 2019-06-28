/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 16:24:04 by thaley            #+#    #+#             */
/*   Updated: 2019/06/28 21:00:35 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void		get_built(char **cmd, int num)
{
	char	*buil;
	pid_t 	pid;
	pid_t 	wpid;
	int		status;
	char	*path = NULL;
	int	i;

	buil = NULL;
	if (num == 1)
		buil = ft_strjoin("/bin/", cmd[0]);
	else if (num == 2)
		buil = ft_strjoin("/usr/bin/", cmd[0]);
	i = env_start("PWD=");
	path = ft_strsub(env[i], 4, ft_strlen(env[i]) - 4);
	pid = fork();
	if (pid == 0)
	{
		if (execve(buil, cmd, env) == -1)
			perror("hz");
		if (buil)
			free(buil);
		return ;
	}
	else if (pid < 0)
		perror("2hs");
	else
	{
		do{
			wpid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	if (buil)
		free(buil);
}

void		execute_cmds(char **cmds)
{
	char	**cmd;
	int		i;

	i = 0;
	while (cmds[i])
	{
		cmd = NULL;
		cmd = split_all(cmds[i]);
		if (check_builtin(cmd) || check_utility(cmd));
		else
			erroring(NULL, cmd[0], 3);	
		if (cmd)
			free_array(&cmd);
		i++;
	}
	if (cmds)
		free_array(&cmds);
}
