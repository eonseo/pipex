/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 08:14:06 by eonoh             #+#    #+#             */
/*   Updated: 2024/08/07 08:14:16 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_file(char argv[])
{
	int	fd;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
	{
		strerror(errno);
		exit(EXIT_FAILURE);
	}
}

int	check_path(char argv[], char *envp[])
{
	char	**command;
	char	**env;
	char	*path;
	int		mode;
	int		access_result;

	command = ft_split(argv, " ");
	env = ft_split(envp, ":");
	mode = F_OK | X_OK;
	while (env)
	{
		path = ft_strjoin(*env, command[0]);
		access_result = access(path, mode);
		free(path);
		if (access_result == 0)
			return (0);
		env++;
	}
	return (-1);
}

void	check_argv(char *argv[], char *envp[])
{
	int	i;

	i = 1;
	while (i < 5)
	{
		if (argv[i] == NULL)
			error("Incorrect number of argument.\n");
		if (i == 1 || i == 4)
			check_file(argv[i]);
		else
		{
			if (check_path(argv[i], envp) < 0)
				error("Invalid command error.\n");
		}
		i++;
	}
	if (argv[5] != NULL)
		error("Incorrect number of argument.\n");
}
