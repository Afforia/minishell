/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enviroment.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 15:04:17 by thaley            #+#    #+#             */
/*   Updated: 2019/06/27 22:17:56 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void		change_pwd()
{
	int		pwd_pos;
	int		oldpwd_pos;
	char	buf[4097];
	char	*cwd;
	char	*tmp;

	cwd = getcwd(buf, 4096);
	pwd_pos = env_start("PWD=");
	oldpwd_pos = env_start("OLDPWD=");
	if (env[oldpwd_pos])
		free(env[oldpwd_pos]);
	env[oldpwd_pos] = ft_strjoin("OLD", env[pwd_pos]);
	if (env[pwd_pos])
		free(env[pwd_pos]);
	env[pwd_pos] = ft_strjoin("PWD=", cwd);
}

int			env_start(char *search_string)
{
	int		i;
	int		j;
	int		len;

	i = -1;
	len = ft_strlen(search_string);
	while (env[++i])
	{
		j = -1;
		while (env[i][++j] && j < len)
		{
			if (env[i][j] == search_string[j] && search_string[j + 1] == '\0')
				return (i);
			else if (env[i][j] != search_string[j])
				break ;
		}
	}
	return (-1);
}

char		*parse_path(char *env, int	start)
{
	char	*new;

	if (!env)
		return (NULL);
	new = ft_strsub(env, start, (ft_strlen(env) - start));
	return (new);
}
