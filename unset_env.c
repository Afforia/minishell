/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 18:38:24 by thaley            #+#    #+#             */
/*   Updated: 2019/06/26 19:12:14 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char		**delet_env(int pos)
{
	char	**new;
	int		len;
	int		i;
	int		j;

	len = 0;
	i = 0;
	j = 0;
	if (pos == 0)
		j++;
	while (env[len])
		len++;
	new = (char **)malloc(sizeof(char *) * len - 1);
	free(env[pos]);
	env[pos] = NULL;
	new[len - 1] = NULL;
	while (--len >=0)
	{
		if (env[j] != NULL)
		{
			new[i] = ft_strdup(env[j]);
			free(env[j]);
		}
		i++;
		j++;
	}
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
		env = delet_env(pos);
	free(tmp);
}
