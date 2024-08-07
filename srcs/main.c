/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 21:44:20 by eonoh             #+#    #+#             */
/*   Updated: 2024/08/08 03:34:47 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

typedef struct s_test
{
	char *s;
	int i;
} t_test;


char	*store_path(char *envp[])
{
	char	*path;

	path = NULL;
	while (*envp)
	{
		if (ft_strncmp(*envp, "PATH=", 5) == 0)
			path = *envp;
		*envp++;
	}
	if (path = NULL)
		error("Can't find path in envp.\n");
	return (path);
}

int main(int argc, char *argv[], char *envp[])
{
	const char	**env = {store_path(envp), NULL};
	t_test test;

	test = (t_test){NULL, 0};
	if (argc != 5)
		error("Incorrect number of argument.\n");
	check_argv(argv, envp);
	pipe_file_io(argv);
}