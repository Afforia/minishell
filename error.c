/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 16:57:25 by thaley            #+#    #+#             */
/*   Updated: 2019/07/05 17:32:35 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void		cd_errors(char *cmd, char *str, int error)
{
	char	*tmp;

	if (cmd)
	{
		if (error == 1)
			tmp = ft_strjoin(cmd, ": no such file or directory: ");
		if (error == 2)
			tmp = ft_strjoin(cmd, ": string not in pwd: ");
	}
	else
	{
		if (error == 1)
			tmp = ft_strdup("no such file or directory: ");
		if (error == 2)
			tmp = ft_strdup("string not in pwd: ");
	}
	ft_putstr_fd(tmp, 2);
	ft_putendl_fd(str, 2);
	free(tmp);
}

void		erroring(char *cmd, char *str, int error)
{
	if (error == 1 || error == 2)
		cd_errors(cmd, str, error);
	else if (error == 3)
	{
		ft_putstr("minishell: command not found: ");
		ft_putendl_fd(str, 2);
	}
	else if (error == 4)
	{
		if (!ft_strcmp(cmd, "cd"))
			ft_putstr("cd: permission denied: ");
		else
			ft_putstr("minishell: permission denied: ");
		ft_putendl_fd(str, 2);
	}
}
