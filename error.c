/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 20:19:32 by thaley            #+#    #+#             */
/*   Updated: 2019/06/27 21:23:54 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void		erroring(char *cmd, char *str, int error)
{
	if (!(ft_strcmp(str, "cd")))
	{
		switch(error)
		{
			case 1:
				ft_putstr("cd: no such file or directory: ");
				ft_putendl(str);
			case 2:
				ft_putstr("cd: string not in pwd: ");
				ft_putendl(str);
			default:
				break ;
		}
	}
}
