/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enviroment.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 15:04:17 by thaley            #+#    #+#             */
/*   Updated: 2019/06/27 16:33:54 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void		change_pwd(char *new_pwd)
{
	int		pwd_pos;
	int		oldpwd_pos;
	char	*pwd;

	pwd = NULL;
	pwd_pos = env_start("PWD=");
	oldpwd_pos = env_start("OLDPWD=");
	if (new_pwd[0] == '.' && (new_pwd[1] == '.' || new_pwd[1] == '/'))
		new_pwd = take_full_path(new_pwd);
	pwd = ft_strsub(env[pwd_pos], 4, ft_strlen(env[pwd_pos]) - 4);
	rewrite_env(pwd_pos, "PWD=", new_pwd);
	rewrite_env(oldpwd_pos, "OLDPWD=", pwd);
	free(pwd);
	free(new_pwd);
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
