/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enviroment.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 22:06:28 by thaley            #+#    #+#             */
/*   Updated: 2019/07/02 22:06:31 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void		change_pwd(void)
{
	int		pwd_pos;
	int		oldpwd_pos;
	char	buf[4097];
	char	*cwd;
	char	*tmp;

	cwd = getcwd(buf, 4096);
	pwd_pos = env_start("PWD=");
	oldpwd_pos = env_start("OLDPWD=");
	if (g_env[oldpwd_pos])
		free(g_env[oldpwd_pos]);
	g_env[oldpwd_pos] = ft_strjoin("OLD", g_env[pwd_pos]);
	if (g_env[pwd_pos])
		free(g_env[pwd_pos]);
	g_env[pwd_pos] = ft_strjoin("PWD=", cwd);
}

int			env_start(char *search_string)
{
	int		i;
	int		j;
	int		len;

	i = -1;
	len = ft_strlen(search_string);
	while (g_env[++i])
	{
		j = -1;
		while (g_env[i][++j] && j < len)
		{
			if (g_env[i][j] == search_string[j] && search_string[j + 1] == '\0')
				return (i);
			else if (g_env[i][j] != search_string[j])
				break ;
		}
	}
	return (-1);
}

char		*parse_path(char *g_env, int start)
{
	char	*new;

	if (!g_env)
		return (NULL);
	new = ft_strsub(g_env, start, (ft_strlen(g_env) - start));
	return (new);
}
