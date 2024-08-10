/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 21:44:20 by eonoh             #+#    #+#             */
/*   Updated: 2024/08/10 23:00:40 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*store_path(char *envp[])
{
	char	*path;
	int		i;

	path = NULL;
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			path = envp[i] + 5;
		i++;
	}
	if (path == NULL)
		error("Can't find path in envp.\n");
	return (path);
}

char	*find_path(char *argv, char *env)
{
	char	**paths;
	char	**command;
	char	*path;
	int		mode;

	paths = ft_split(env, ':');
	for (int i = 0; paths[i]; i++)
		printf("paths[%d]: %s\n", i, paths[i]);
	command = ft_split(argv, ' ');
	for (int i = 0; command[i]; i++)
		printf("command[%d] = %s\n", i, command[i]);
	mode = F_OK | X_OK;
	path = NULL;
	while (*paths)
	{
		path = ft_strjoin(*paths, *command);
		if ((access(path, mode)) == 0)
			break;
		free(path);
		(*path)++;
	}
	if (path == NULL)
		error ("path\n");
	return (path);
}

int main(int argc, char *argv[], char *envp[])
{
	int		fd[2];
	// int		pid;
	char	*env;

	// argc가 5개가 아니면 error
	if (!argc || !argv)
		error("argc\n");
	env = store_path(envp);
	if (pipe(fd) == -1)
		error("pipe\n");
	printf("path = %s\n", find_path(argv[1], env));
	// pid = fork();
	// if (pid == 0)
	// 	child_process();
	// if (pid > 0)
	// 	parents_process();
	return 0;
}