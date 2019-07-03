/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 18:38:24 by thaley            #+#    #+#             */
/*   Updated: 2019/07/03 18:19:52 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char		**crt_new_env(char **new, int pos, int len)
{
	int		j;
	int		i;

	i = 0;
	j = 0;
	while (len > 0 && g_env[j])
	{
		if (j == pos)
			j++;
		else if (j != pos)
		{
			if (!(new[i] = ft_strdup(g_env[j])))
				exit_shell(new, -1);
			len--;
			j++;
			i++;
		}
	}
	new[i] = NULL;
	return (new);
}

char		**delet_env(int pos)
{
	char	**new;
	int		len;

	len = 0;
	while (g_env[len])
		len++;
	if (!(new = (char **)malloc(sizeof(char *) * len)))
		exit_shell(NULL, -1);
	new = crt_new_env(new, pos, len);
	free_array(g_env);
	return (new);
}

void		unset_env(char **cmd)
{
	int		pos;
	char	*tmp;

	if (cmd[0] == NULL || cmd[1] != NULL)
		return ;
	tmp = ft_strjoin(cmd[0], "=");
	if ((pos = env_start(tmp)) < 0)
	{
		free(tmp);
		return ;
	}
	else
		g_env = delet_env(pos);
	free(tmp);
}
