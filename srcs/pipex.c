/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 21:44:20 by eonoh             #+#    #+#             */
/*   Updated: 2024/08/11 01:57:35 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char *argv[], char *envp[])
{
	int			fd[2];
	int			pid1;
	int			pid2;
	const char	*env[] = {store_path(envp), NULL};

	// argc가 5개가 아니면 error
	if (!argc || !argv)
		error("argument\n");
	if (pipe(fd) == -1)
		error("pipe\n");
	pid1 = fork();
	if (pid1 == -1)
		error("fork\n");
	if (pid1 == 0)
		child_process();
	if (pid1 > 0)
	{
		pid2 = fork();
		parents_process();
	}
	exit (0);
}
