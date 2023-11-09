#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE BUFSIZ
# endif

# if BUFFER_SIZE > 9223372036854775806
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
int		ft_strlen(char *str);
int		has_newline_inside(const char *s);
char	*check_line(char *stash);
void	ft_free_strs(char **str_1, char **str_2, char **str_3);
char	*ft_parse(char **stash, char **temp);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strdup(const char *s);
void	*ft_calloc(size_t count, size_t size);
char	*get_after_newline(const char *s);
char	*get_before_newline(const char *s);

#endif