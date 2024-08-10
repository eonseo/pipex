/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 08:15:37 by eonoh             #+#    #+#             */
/*   Updated: 2024/08/11 02:00:57 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(int *pipefd, char *filename, const char *env[], )
{
	int		filefd;
	char	*buf;
	char	*path;

	close(pipefd[0]);
	filefd = open(filename, O_RDONLY);
	if (filefd == -1)
		error("file open\n");
	dup2(filefd, STDIN_FILENO);
	dup2(pipefd[1], STDOUT_FILENO);
	path = find_path(argv[1], env[0]);
	execve()
	close(pipefd[1]);
	close(filefd);
}

void	parents_process(int *fd, char *filename)
{
	int	filefd;

	close(fd[1]);
	filefd = open(filename, O_WRONLY | O_TRUNC )
}
