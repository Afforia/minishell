/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enviroment.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 15:04:17 by thaley            #+#    #+#             */
/*   Updated: 2019/06/26 17:44:19 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void		new_pwd(char *path)
{
	char	*tmp;
	int		pwd_pos;
	int		old_pwd_pos;

	pwd_pos = env_start("PWD=");
	old_pwd_pos = env_start("OLDPWD=");
	tmp = ft_strsub(env[pwd_pos], 4, ft_strlen(env[pwd_pos]) - 4);
	free(env[pwd_pos]);
	free(env[old_pwd_pos]);
	env[pwd_pos] = ft_strjoin("PWD=", path);
	env[old_pwd_pos] = ft_strjoin("OLDPWD=", tmp);
	free(tmp);
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
