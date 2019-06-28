/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 14:11:03 by thaley            #+#    #+#             */
/*   Updated: 2019/06/28 21:02:15 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		len_env(char **envp)
{
	int		len;

	len = 0;
	while (envp[len])
		len++;
	return (len);
}

void	write_env(char **envp)
{
	int		i;
	int		pwd;
	char	*tmp;

	if (!(env = (char **)malloc(sizeof(char *) * len_env(envp) + 1)))
		exit_shell(NULL, -1);
	i = 0;
	while (envp[i])
	{
		if (!(env[i] = ft_strdup(envp[i])))
			exit_shell(NULL, -1);
		i++;
	}
	env[i] = NULL;
	i = env_start("ZSH=");
	pwd = env_start("_=");
	tmp = ft_strsub(env[pwd], 2, ft_strlen(env[pwd]) - 2);
	rewrite_env(i, "ZSH=", tmp);
	free(tmp);
}

char	*ft_realloc(char *str, int i)
{
	char *tmp;

	tmp = NULL;
	if (i == 0)
		str = ft_strnew(1);
	else
	{
		tmp = ft_strdup(str);
		free(str);
		str = (char *)malloc(sizeof(char) * i + 2);
		str = ft_strcpy(str, tmp);
		free(tmp);
	}
	return (str);
}

char	*take_input(void)
{
	int		ret;
	char	buf;
	char	*new;
	int		i;

	i = 0;
	while ((ret = read(0, &buf, 1)) && buf != '\n')
	{
		new = ft_realloc(new, i);
		new[i] = buf;
		new[i + 1] = '\0';
		i++;
	}
	return (new);
}

int		main(int argc, char **argv, char **envp)
{
	char	*input;
	char	**cmds;

	write_env(envp);
	while (1)
	{
		print_welcome_msg();
		signal(SIGINT, SIG_DFL);
		input = take_input();
		cmds = split_cmds(input);
		execute_cmds(cmds);
	}
	return (0);
}
