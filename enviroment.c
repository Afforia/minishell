/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enviroment.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 15:04:17 by thaley            #+#    #+#             */
/*   Updated: 2019/06/25 16:11:51 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		env_start(char *env, char *search_string)
{
	int		i;
	int		len;

	len = ft_strlen(search_string);
	i = 0;
	while (env[i] && search_string[i] && len)
	{
		if (env[i] != search_string[i])
			return (0);
		i++;
		len--;
	}
	return (1);
}
