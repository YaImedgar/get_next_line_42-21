/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imedgar <imedgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 01:10:27 by imedgar           #+#    #+#             */
/*   Updated: 2020/05/13 01:10:40 by imedgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

typedef struct		s_gnl
{
	int				fd;
	int				end;
	char			*tail;
	char			*start_tail;
	char			*line_back_up;
	struct s_gnl	*next;
}					t_gnl;

int					get_next_line(int fd, char **line);
t_gnl				*ft_lst_new(int fd);
t_gnl				*ft_find_lst(int fd, t_gnl **prime);
char				*ft_strchr(const char *s, int c);
char				*ft_strdup(const char *s);
int					ft_exit(char *buf, int fd, t_gnl **prime, int result);

#endif