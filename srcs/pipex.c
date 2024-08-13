/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 21:44:20 by eonoh             #+#    #+#             */
/*   Updated: 2024/08/13 14:23:18 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char *argv[], char *envp[])
{
	int			pipefd[2];
	int			pid1;
	int			pid2;
	char *const	env[] = {store_path(envp), NULL};

	if (argc != 5 || !argv)
		error("argument\n");
	if (pipe(pipefd) == -1)
		error("pipe\n");
	pid1 = fork();
	if (pid1 < 0)
		error("first fork\n");
	else if (pid1 == 0)
		first_child_process(pipefd, argv, env);
	else
	{
		wait(NULL);
		pid2 = fork();
		if (pid2 < 0)
			error("second fork\n");
		else if (pid2 == 0)
			second_child_process(pipefd, argv, env);
		else
			wait(NULL);
	}
	exit (EXIT_SUCCESS);
}
