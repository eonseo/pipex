/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 21:44:20 by eonoh             #+#    #+#             */
/*   Updated: 2024/08/17 23:25:38 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	int			pipefd[2];
	int			pid1;
	int			pid2;
	char *const	env[] = {store_path(envp), NULL};

	if (argc != 5)
		error("argument error\n", 1);
	if (pipe(pipefd) == -1)
		error("pipe error\n", 1);
	pid1 = fork();
	if (pid1 < 0)
		error("first fork\n", 1);
	else if (pid1 == 0)
		first_child_process(pipefd, argv, env);
	else
	{
		pid2 = fork();
		if (pid2 < 0)
			error("second fork\n", 1);
		else if (pid2 == 0)
			second_child_process(pipefd, argv, env);
		else
			parents_process(pipefd);
	}
	exit (EXIT_SUCCESS);
}
