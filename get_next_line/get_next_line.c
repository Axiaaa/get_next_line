/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamerly <lcamerly@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:01:19 by lcamerly          #+#    #+#             */
/*   Updated: 2023/11/10 15:25:57 by lcamerly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

void ft_read_line(int fd, char** temp, char** stash)
{
    int read_byte;
    char *buff;

    read_byte = 1;
    buff = ft_malloc_zero(sizeof(char), (BUFFER_SIZE + 1));
	if (!buff)
		return ;
    while (read_byte > 0)
    {
        read_byte = read(fd, buff, BUFFER_SIZE);
        if (read_byte == -1)
        {
            free_strs(&buff, stash, temp);
            return ;
        }
        buff[read_byte] = '\0';
        *temp = ft_strdup(*stash);
		free_strs(stash, 0, 0);
		*stash = ft_strjoin(*temp, buff);
        if (has_newline_inside(*temp) == 1)
            break;
    }
    free_strs(&buff, 0, 0);
}
char	*ft_get_before_newline(const char *s)
{
	char	*res;
	int		i;

	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	if (s[i] != '\0' && s[i] == '\n')
		i++;
	res = ft_malloc_zero(i + 1, sizeof * res);
	if (!res)
		return (NULL);
	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
	{
		res[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
	{
		res[i] = s[i];
		i++;
	}
	return (res);
}

char	*ft_get_after_newline(const char *s)
{
	char	*res;
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (s && s[j])
		j++;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	if (s[i] != '\0' && s[i] == '\n')
		i++;
	res = ft_malloc_zero((j - i) + 1, sizeof * res);
	if (!res)
		return (NULL);
	j = 0;
	while (s[i + j])
	{
		res[j] = s[i + j];
		j++;
	}
	return (res);
}

char	*ft_parse_line(char **stash, char **temp)
{
	char	*line;

	*temp = ft_strdup(*stash);
	free_strs(stash, 0, 0);
	*stash = ft_get_after_newline(*temp);
	line = ft_get_before_newline(*temp);
	free_strs(temp, 0, 0);
	return (line);
}

char* get_next_line(int fd)
{
    static char* stash;
    char *line;
    char *temp;
    
    line = NULL;
    temp = NULL;
	stash = NULL;
    if (fd < 0 || BUFFER_SIZE <= 0)
    	return (NULL);
    ft_read_line(fd, &temp, &stash);
	if (stash != NULL && *stash != '\0')
		line = ft_parse_line(&stash, &temp);
    if (!line || *line == '\0')
	{
		free_strs(&line, &temp, &stash);
        return (NULL);
	}
    return (line);
}