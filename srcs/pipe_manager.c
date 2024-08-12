/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 08:15:37 by eonoh             #+#    #+#             */
/*   Updated: 2024/08/13 00:04:17 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(int *pipefd, char *argv[], char *const *env[])
{
	int		filefd;
	char	*command;
	char	**command_vec;

	close(pipefd[0]);
	command = find_path(argv[2], env[0]);
	command_vec = ft_split(argv[2], ' ');
	filefd = open(argv[1], O_RDONLY);
	if (filefd < 0)
		error("file open\n");
	dup2(filefd, STDIN_FILENO);
	dup2(pipefd[1], STDOUT_FILENO);
	execve(command, command_vec, env);
	error("execve\n");
}