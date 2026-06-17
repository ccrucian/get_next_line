/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrucian <ccrucian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 18:32:59 by ccrucian          #+#    #+#             */
/*   Updated: 2026/06/17 14:58:14 by ccrucian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*update_backup(char *backup)
{
	char	*update;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (backup[i] && backup[i] != '\n')
		i++;
	if (backup[i] == '\0')
		return (free(backup), NULL);
	i++;
	if (backup[i] == '\0')
		return (free(backup), NULL);
	update = malloc((ft_strlen(backup) - i) + 1);
	if (!update)
		return (free(backup), NULL);
	while (backup[i])
		update[j++] = backup[i++];
	update[j] = '\0';
	free(backup);
	return (update);
}

char	*ft_strdup_newline(char *str)
{
	int		i;
	int		len;
	char	*s;

	i = 0;
	len = 0;
	while (str[len] && str[len] != '\n')
		len++;
	if (str[len] == '\n')
		len++;
	s = malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	while (str[i] && str[i] != '\n')
	{
		s[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

void	free_and_null(char **s)
{
	if (*s)
	{
		free(*s);
		*s = NULL;
	}
}

char	*ft_strchr(char c, char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (&str[i]);
		i++;
	}
	return (NULL);
}

int	ft_strlen(char *s)
{
	int		i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}
