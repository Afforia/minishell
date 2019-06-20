/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 14:11:03 by thaley            #+#    #+#             */
/*   Updated: 2019/06/20 17:47:07 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#define SH_BUFSIZE 1024

int		sh_cd(char **args);
int		sh_help(char **args);
int		sh_exit(char **args);

char	*builtin_str[] = {
	"cd",
	"help",
	"exit"
};

int		(*builtin_func[])(char **) = {
	&sh_cd,
	&sh_help,
	&sh_exit
};

int		sh_num_builtins()
{
	return (sizeof(builtin_str) / sizeof(char *));
}

int		sh_cd(char **args)
{
	if (args[1] == NULL)
	{
		write(2, "need arg for cd\n", 16);
	}
	else
	{
		if (chdir(args[1]) != 0)
			perror("sh");
		
	}
	return (1);
}

int		sh_help(char **args)
{
	int		i;

	i = 0;
	while (i < sh_num_builtins())
	{
		ft_putstr(builtin_str[i]);
		i++;
	}
	return (1);
}

int		sh_exit(char **args)
{
	return (0);
}

char	*sh_read_line(char **argv)
{
	int		bufsize;
	int		pos;
	int		i;
	char	*buf;

	bufsize = SH_BUFSIZE;
	pos = 0;
	i = 1;
	if (!(buf = (char *)malloc(sizeof(char) * bufsize)))
	{
		write(1, "can't allocate memory.", 22);
		exit(EXIT_FAILURE);
	}
	while (argv[i])
	{
		pos = 0;
		while (argv[i][pos])
		{
			buf[pos] = argv[i][pos];
			pos++;
		}
		i++;
	}
	return (buf);
}

char	**sh_split_line(char *line)
{
	int		i;
	int		finish;
	int		start;
	size_t	len;
	char	**new_args;

//FIXME: если только 1 аргумент он не записывается в args

	i = 0;
	finish = 0;
	start = 0;
	len = 0;
	if (!line || line[0] == '\0')
		return (NULL);
	new_args = (char **)malloc(sizeof(char *) * 64);
	while (line[finish])
	{
		if (line[finish] == '\n' || line[finish] == '\t' || line[finish] == ' ')
		{
			new_args[i] = ft_strsub(line, start, len);
			len = 0;
			i++;
			start = finish + 1;
		}
		len++;
		finish++;
	}
	return (new_args);
}

int		sh_launch(char **args, char **envp)
{
	pid_t	pid;
	pid_t	wpid;
	int		status;

	pid = fork();
	if (pid == 0)
	{
		if (execve(args[0], args, envp) == -1)
			perror("error: ");
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
		perror("error: ");
	else
	{
		do
		{
			wpid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));		
	}
	return (1);
}

int		sh_execute(char **args, char **envp)
{
	int		i;

	i = 0;
	if (!args[0])
		return (1);
	while (i < sh_num_builtins())
	{
		if (!ft_strcmp(args[0], builtin_str[i]))
			return ((*builtin_func[i])(args));
		i++;
	}
	return (sh_launch(args, envp));
}

void	sh_loop(char **argv, char **envp)
{
	char	*line;
	char	**args;
	int		status;
	int		i;
	int		j;

	i = 64;
	do
	{
		write(1, ">>", 2);
		if (!(line = sh_read_line(argv)))
			exit(EXIT_FAILURE);
		if (!(args = sh_split_line(line)))
			exit(EXIT_FAILURE);
		status = sh_execute(args, envp);
		if (line)
			free(line);
		if (args)
			free(args);
	} while (status);
	
}

int		main(int argc, char **argv, char **envp)
{
	// while (*envp != NULL)
	// 	printf("%s\n", *(envp++));
	sh_loop(argv, envp);
	return (0);
}