/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 16:57:25 by thaley            #+#    #+#             */
/*   Updated: 2019/06/28 20:20:30 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void		cd_errors(char *str, int error)
{
	if (error == 1)
	{
		ft_putstr("cd: no such file or directory: ");
		ft_putendl(str);
	}
	else if (error == 2)
	{
		ft_putstr("cd: string not in pwd: ");
		ft_putendl(str);
	}
}

void		erroring(char *cmd, char *str, int error)
{
	if (!(ft_strcmp(cmd, "cd")))
		cd_errors(str, error);
	else if (error == 3)
		ft_putstr("minishell: command not found: ");
		ft_putendl(str);
}
