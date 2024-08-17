/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 08:14:06 by eonoh             #+#    #+#             */
/*   Updated: 2024/08/17 23:17:11 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*store_path(char *envp[])
{
	char	*path;
	int		i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			path = envp[i] + 5;
		i++;
	}
	return (path);
}

char	*find_path(char *argv, const char *env)
{
	char	**paths;
	char	**command;
	char	*path;
	int		i;

	paths = ft_split(env, ':');
	command = ft_split(argv, ' ');
	i = 0;
	if (access(command[0], F_OK | X_OK) == 0)
		path = command[0];
	else
	{
		while (paths[i])
		{
			path = ft_strjoin(paths[i], command[0]);
			if ((access(path, F_OK | X_OK)) == 0)
				break;
			i++;
			free(path);
		}
	}
	if (paths[i] == NULL)
		path = NULL;
	free_path(paths, command);
	return (path);
}
