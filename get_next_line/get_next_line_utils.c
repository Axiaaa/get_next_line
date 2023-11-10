/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamerly <lcamerly@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:24:21 by lcamerly          #+#    #+#             */
/*   Updated: 2023/11/10 15:16:22 by lcamerly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s)
{
	int		len;
	int		i;
	char	*dest;

	len = 0;
	i = 0;
	if (!s)
		return (ft_strdup(""));
	while (s[len])
		len++;
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void *ft_malloc_zero(size_t nmemb, size_t size)
{
	void			*r;
	unsigned char	*ptr;
	size_t			total;

	total = nmemb * size;
	r = malloc(total);
	if (!r)
		return (NULL);
	ptr = (unsigned char *)r;
	while (total != 0)
	{
		*ptr = '\0';
		ptr++;
		total--;
	}
	return (r);
}

void free_strs(char** str1, char** str2, char** str3)
{
    if (str1 && *str1)
    {
        free(*str1);
        *str1 = NULL;
    }
    if (str2 && *str2)
    {
        free(*str2);
        *str2 = NULL;
    }
    if (str3 && *str3)
    {
        free(*str3);
        *str3 = NULL;
    }
}

int has_newline_inside(char *s)
{
    int i;

    i = 0;
    while (s[i])
    {
        if (s[i++] == '\n')
            return (1);
    }
    return (0);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		j;
	int		k;
	char	*dest;

	i = 0;
	j = 0;
	k = -1;
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	dest = malloc(sizeof(char) * (i + j + 1));
	if (!dest)
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++i])
		dest[++k] = s1[i];
	while (s2[++j])
		dest[++k] = s2[j];
	dest[++k] = '\0';
	return (dest);
}
