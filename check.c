/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 20:54:48 by thaley            #+#    #+#             */
/*   Updated: 2019/07/03 16:04:27 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char		*take_define(char *cmds, int start)
{
	char	*new;
	int		pos;
	char	*temp;
	int		len;

	len = start;
	while (cmds[len])
	{
		if (SPES_CHAR(cmds[len]) || MORE_SPES_CHAR(cmds[len]))
			break ;
		len++;
	}
	new = ft_strsub(cmds, start, len - start);
	start = len;
	temp = ft_strjoin(new, "=");
	free(new);
	if ((pos = env_start(temp)) == -1)
	{
		free(temp);
		return (NULL);
	}
	len = ft_strlen(temp);
	new = ft_strsub(g_env[pos], len, ft_strlen(g_env[pos]) - len);
	free(temp);
	return (new);
}

int			check_define(char **cmd)
{
	int		i;
	char	*tmp;

	i = -1;
	while (cmd[++i])
	{
		if (cmd[i][0] == '$' || (cmd[i][1] == '$'))
		{
			if (cmd[i][0] == '$')
				tmp = take_define(cmd[i], 1);
			else
				tmp = take_define(cmd[i], 2);
			free(cmd[i]);
			if (!tmp)
			{
				cmd[i] = NULL;
				return (1);
			}
			cmd[i] = ft_strdup(tmp);
			free(tmp);
		}
	}
	return (0);
}

int			check_dir(char *cmd)
{
	if (!(ft_strcmp(cmd, "cd")))
		return (1);
	if (cmd[0] == '/')
	{
		if (access(cmd, F_OK))
		{
			erroring(NULL, cmd, 1);
			return (0);
		}
	}
	return (1);
}
