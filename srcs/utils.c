/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 01:05:11 by eonoh             #+#    #+#             */
/*   Updated: 2024/08/14 20:36:35 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(char *s)
{
	errno ;
	if (s)
		perror(s);
	exit(EXIT_FAILURE);
}

void	free_path(char **paths, char **command)
{
	int	i;

	i = 0;
	while (paths[i])
	{
		free(paths[i]);
		i++;
	}
	free(paths);
	paths = NULL;
	i = 0;
	while (command[i])
	{
		free(command[i]);
		i++;
	}
	free(command);
	command = NULL;
}
