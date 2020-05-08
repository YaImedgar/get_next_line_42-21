#include <stdio.h>
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imedgar <imedgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 10:44:17 by imedgar           #+#    #+#             */
/*   Updated: 2020/05/06 16:55:03 by imedgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char			*ft_strcpy_mod(char **line, char **src, int ret[][2])
{
	char	*p_n;
	char	*tmp;

	if ((*src) == NULL)
		return (ft_calloc(1, 1));
	if (!(p_n = ft_strchr((*src), '\n')))
		ft_strcpy(((*line) = malloc(ft_strlen(*src) + 1)), *src);
	else
	{
		(*src)[p_n - (*src)] = '\0';
		ft_strcpy(((*line) = malloc(ft_strlen(*src) + 1)), *src);
		tmp = (*src);
		if (!((*src) = ft_strdup(++p_n)))
			return (NULL);
		free(tmp);
		if (!(p_n = ft_strchr((*src), '\n')))
			(*ret)[1] = 0;
		else
			(*ret)[1] = 1;
		if (!ft_strcmp((*line), (*src)))
			free (*src);
	}
	return (*line);
}

static char			*ft_strjoin(char const *s1, char const *s2)
{
	const int 	len_s1 = (s1? ft_strlen(s1) : 0);
	char *new;
	const char *tmp = s1;
	char *ptr;

	if (!(new = (char *)malloc(len_s1 + ft_strlen(s2) + 1)))
		return (NULL);
	ptr = new;
	if (s1)
	{
		while (*s1)
			*ptr++ = *s1++;
	}
	while (*s2)
		*ptr++ = *s2++;
	*ptr = '\0';
	if (tmp)
		free((char *)tmp);
	return (new);
}

static char			*ft_line_sep(char buf[], char *p_n, char **tail, int ret[][2])
{
	char	*p_ntmp;

	*p_n++ = '\0';
printf("buf		= %s\n", buf);
	if (!(p_ntmp = ft_strchr(p_n, '\n')));
	{
		return (ft_strjoin((*line), buf));
	}
	else
	{
		if (tmp->tail != NULL && !(tmp->tail = ft_strjoin(tmp->tail, p_n)))
		{
			return (NULL);
		}
		else if (!(tmp->tail = ft_strdup(&buf[p_n - buf + 1])))
			return (NULL);
	}
	return (NULL);
}

int					get_next_line(int fd, char **line)
{
	static t_list	*prime;
	t_list			*tmp;
	char			buf[BUFFER_SIZE + 1];
	char			*p_n;
	int				ret[2];

	ret[1] = 0;
	if (!(fd == 0 || fd > 2) || !(tmp = ft_find_lst(&prime, fd)) ||
		!((*line) = ft_strcpy_mod(line, &tmp->tail, &ret)))
		return (-1);
	if (!ret[1])
		while ((ret[0] = read(fd, buf, BUFFER_SIZE)) != 0)
		{
			buf[ret[0]] = '\0';
			if ((p_n = ft_strchr(buf, '\n')))
			{
				if (!(*line = ft_line_sep(buf, p_n, &tmp->tail, &ret)))
					return (-1);
				break;
			}
			else
				*line = ft_strjoin((*line), buf);
printf("line	= %s\n", (*line));
printf("last	= %s\n", tmp->tail);
		}
	return (!ret[0] && !ret[1] ? 0 : 1);
}
