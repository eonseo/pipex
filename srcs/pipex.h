/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonoh <eonoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 01:06:19 by eonoh             #+#    #+#             */
/*   Updated: 2024/08/10 06:26:25 by eonoh            ###   ########.fr       */
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

void	error(char *s);

#endif