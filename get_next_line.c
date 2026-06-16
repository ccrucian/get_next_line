/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrucian <ccrucian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 18:31:56 by ccrucian          #+#    #+#             */
/*   Updated: 2026/06/11 16:59:54 by ccrucian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
*	
*/
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
	char	buffer[BUFFER_SIZE + 1];
	ssize_t		bytes_read;

	while (!ft_strchr('\n', backup))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(backup), NULL);
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		backup = join_buffer(backup, buffer);
		if (!backup)
			return NULL;
	}
	return (backup);
}


char	*get_next_line(int fd)
{
	char	*line;
	static char	*backup;
	
	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!backup)
	{
		backup = malloc(1);
		if (!backup)
			return (NULL);
		backup[0] = '\0';
	}
	backup = save_in_backup(backup, fd);
	if (!backup)
		return NULL;
	if (backup[0] == '\0')
	{
		free(backup);
		backup = NULL;
		return NULL;
	}
	line = ft_strdup_newline(backup);
	backup = update_backup(backup);
	return (line);
}

int main(void)
{
    int     fd;
    char    *str;
	int		i;

	i = 79;
    fd = open("subject_getnextline.md", O_RDONLY);
    str = get_next_line(fd);
    while (str && i)
	{
		printf("%s", str);
		free(str);
        str = get_next_line(fd);
		i--;
    }
    close(fd);
    return (0);
}
