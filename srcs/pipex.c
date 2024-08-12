/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 21:44:20 by eonoh             #+#    #+#             */
/*   Updated: 2024/08/12 15:22:16 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char *argv[], char *envp[])
{
	int			pipefd[2];
	int			pid1;
	// int			pid2;
	char *const	*env[] = {store_path(envp), NULL};

	// argc가 5개가 아니면 error
	if (!argc || !argv)
		error("argument\n");
	if (pipe(pipefd) == -1)
		error("pipe\n");
	pid1 = fork();
	if (pid1 == -1)
		error("fork\n");
	if (pid1 == 0)
		child_process(pipefd, argv, env);
	// if (pid1 > 0)
	// {
	// 	wait(NULL);
	// 	pid2 = fork();
	// 	parents_process();
	// }
	exit (0);
}
