/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccrucian <ccrucian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 14:44:24 by ccrucian          #+#    #+#             */
/*   Updated: 2026/06/11 15:13:42 by ccrucian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
    }
    close(fd);
    return (0);
}