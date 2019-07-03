/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 17:23:53 by thaley            #+#    #+#             */
/*   Updated: 2019/07/02 22:04:28 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void		rewrite_env(int pos, char *name, char *value)
{
	free(g_env[pos]);
	g_env[pos] = NULL;
	g_env[pos] = ft_strjoin(name, value);
}

char		**add_env(char *name, char *value, int len)
{
	char	**new;
	int		i;

	i = 0;
	new = (char **)malloc(sizeof(char *) * len + 1);
	while (g_env[i])
	{
		new[i] = ft_strdup(g_env[i]);
		i++;
	}
	free_array(g_env);
	new[i] = ft_strjoin(name, value);
	new[i + 1] = NULL;
	return (new);
}

int			set_env_aux(char *name, char *value, int overwrite)
{
	int		pos;
	char	*tmp;
	int		len;

	len = 0;
	tmp = ft_strjoin(name, "=");
	if ((pos = env_start(tmp)) < 0)
	{
		while (g_env[len])
			len++;
		g_env = add_env(tmp, value, len + 1);
	}
	else if (overwrite)
		rewrite_env(pos, tmp, value);
	free(tmp);
	return (1);
}

int			set_env(char **cmd)
{
	int		overwrite;

	overwrite = 0;
	if (cmd[1] && cmd[2] != NULL)
		overwrite = ft_atoi(cmd[2]);
	if (!cmd[0])
	{
		print_env();
		return (1);
	}
	if (cmd[1] && !overwrite && (cmd[2] != NULL && cmd[2][0] != '0'))
	{
		ft_putstr("setg_env: Too many arguments.");
		return (1);
	}
	if (cmd[2])
		set_env_aux(cmd[0], cmd[1], overwrite);
	else
		set_env_aux(cmd[0], cmd[1], 0);
	return (1);
}
