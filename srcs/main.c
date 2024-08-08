/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 21:44:20 by eonoh             #+#    #+#             */
/*   Updated: 2024/08/08 22:00:00 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

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

int main(int argc, char *argv[], char *envp[])
{
	//int			pipefd[2];
	char	*env = store_path(envp);


	printf("env = %s\n", env);
	//if (argc != 5)
	//	error("Incorrect number of argument.\n");
	//if (pipe(pipefd) == -1)
	//	error("pipe error\n");
	//pipe_io(pipefd, env);
}