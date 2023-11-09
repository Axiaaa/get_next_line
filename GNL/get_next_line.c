#include "get_next_line.h"

char	*ft_parse(char **stash, char **temp)
{
	char	*line;

	*temp = ft_strdup(*stash);
	ft_free_strs(stash, 0, 0);
	*stash = get_after_newline(*temp);
	line = get_before_newline(*temp);
	ft_free_strs(temp, 0, 0);
	return (line);
}

void	ft_read_line(int fd, char **stash, char **temp)
{
	char	*buff;
	int		r;

	buff = malloc(sizeof(buff) * (BUFFER_SIZE + 1));
	if (!buff)
		return ;
	r = 1;
	while (r > 0)
	{
		r = read(fd, buff, BUFFER_SIZE);
		if (r == -1)
		{
			ft_free_strs(&buff, stash, temp);
			return ;
		}
		buff[r] = '\0';
		*temp = ft_strdup(*stash);
		ft_free_strs(stash, 0, 0);
		*stash = ft_strjoin(*temp, buff);
		ft_free_strs(temp, 0, 0);
		if (has_newline_inside(*stash))
			break ;
	}
	ft_free_strs(&buff, 0, 0);
}

void	ft_free_strs(char **str_1, char **str_2, char **str_3)
{
	if (str_1 && *str_1)
	{
		free(*str_1);
		*str_1 = NULL;
	}
	if (str_2 && *str_2)
	{
		free(*str_2);
		*str_1 = NULL;
	}
	if (str_3 && *str_3)
	{
		free(*str_3);
		*str_1 = NULL;
	}
}

int	has_newline_inside(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char		*temp;
	static char	*stash;
	char		*line;

	stash = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp = NULL;
	line = NULL;
	ft_read_line(fd, &stash, &temp);
	if (stash != NULL && *stash != '\0')
		line = ft_parse(&stash, &temp);
	if (!line || *line == '\0')
	{
		ft_free_strs(&stash, &temp, &line);
		return (NULL);
	}
	return (line);
}
