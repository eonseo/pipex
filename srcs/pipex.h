/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 01:06:19 by eonoh             #+#    #+#             */
/*   Updated: 2024/08/11 02:01:00 by eonoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <string.h>
# include <fcntl.h>
# include <errno.h>
#include <stdio.h>

#include "../libft/libft.h"

//path.c
char	*store_path(char *envp[]);
char	*find_path(char *argv, const char *env);

//pipe_manager.c
void	child_process(char *argv[]);

//error.c
void	error(char *s);

#endif