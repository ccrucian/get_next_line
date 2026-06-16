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

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

char	*get_next_line(int fd);
char	*save_in_backup(char *backup, int fd);
char    *join_buffer(char *backup, char *buffer);
char    *ft_strdup_newline(char *str);
char    *ft_strchr(char c, char *str);
void    free_and_null(char *s)
int     ft_strlen(char *s)
char    *update_backup(char *backup);

#endif
