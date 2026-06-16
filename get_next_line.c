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
*	Counts how many '\n' characters are in the string.
*/
int	count_newline(char *buffer)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			count++;
		i++;
	}
	return (count);
}



/*
*	
*/
char	*save_in_backup(char *backup, int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t		bytes_read;

	while (!ft_strchr('\n', backup))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(backup);
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		backup = join_buffer(backup, buffer);
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
	line = ft_strdup_newline(backup);
	backup = update_backup(backup);
	return (line);
}

int main(void)
{
    int     fd;
    char    *str;

    fd = open("text.txt", O_RDONLY);
    str = get_next_line(fd);
    while (str)
    {
        str = get_next_line(fd);
        printf("%s\n", str);
		free(str);
    }
    close(fd);
    return (0);
}
