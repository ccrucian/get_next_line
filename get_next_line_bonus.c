/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrucian <ccrucian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 18:31:56 by ccrucian          #+#    #+#             */
/*   Updated: 2026/06/17 14:50:46 by ccrucian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*join_buffer(char *backup, char *buffer)
{
	int		i;
	int		j;
	char	*joint;

	i = 0;
	j = 0;
	joint = malloc(ft_strlen(backup) + ft_strlen(buffer) + 1);
	if (!joint)
		return (free(backup), NULL);
	while (backup[i])
	{
		joint[i] = backup[i];
		i++;
	}
	while (buffer[j])
		joint[i++] = buffer[j++];
	joint[i] = '\0';
	free(backup);
	return (joint);
}

char	*save_in_backup(char *backup, int fd)
{
	char	*buffer;
	ssize_t	bytes_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!ft_strchr('\n', backup))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(buffer), free(backup), NULL);
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		backup = join_buffer(backup, buffer);
		if (!backup)
			return (NULL);
	}
	free(buffer);
	return (backup);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*backup[FD_SIZE];

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	if (!backup[fd])
	{
		backup[fd] = malloc(1);
		if (!backup[fd])
			return (NULL);
		backup[fd][0] = '\0';
	}
	backup[fd] = save_in_backup(backup[fd], fd);
	if (!backup[fd])
		return (NULL);
	if (backup[fd][0] == '\0')
		return (free_and_null(&backup[fd]), NULL);
	line = ft_strdup_newline(backup[fd]);
	if (!line)
		return (free(line), NULL);
	backup[fd] = update_backup(backup[fd]);
	return (line);
}
