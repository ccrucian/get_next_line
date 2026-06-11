/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrucian <ccrucian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 18:25:29 by ccrucian          #+#    #+#             */
/*   Updated: 2026/06/11 15:18:02 by ccrucian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# define BUFFER_SIZE 1024

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

char	*get_next_line(int fd);

#endif
