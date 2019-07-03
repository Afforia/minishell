/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 21:13:07 by thaley            #+#    #+#             */
/*   Updated: 2019/07/02 21:14:11 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		count_words(char *input)
{
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (input[i])
	{
		if (input[i] && SPACES(input[i]))
			i++;
		if (input[i] && !SPACES(input[i]))
			len++;
		while (input[i] && !SPACES(input[i]))
			i++;
	}
	return (len);
}

int		word_len(char *input, int i)
{
	int		len;

	len = 0;
	while (input[i + len])
	{
		if (SPACES(input[i + len]))
			return (len);
		len++;
	}
	return (len);
}

int		count_cmds(char *str)
{
	int		i;
	int		count;

	count = 1;
	i = -1;
	while (str[++i])
	{
		if (str[i] == ';')
			count++;
	}
	return (count);
}
