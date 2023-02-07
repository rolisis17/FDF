/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 18:24:32 by dcella-d          #+#    #+#             */
/*   Updated: 2023/02/07 12:36:18 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

char	*get_next_line(int fd);

void	*ft_calloc_gnl(size_t nmemb, size_t size);

char	*ft_strjoin_gnl(char *s1, char *s2, int f);

int		ft_strlen_gnl(const char *s);

int		gnl_check(char *line);

char	*full_line(int fd, char *keep);

char	*makeline(char *keep, int posnextline);

#endif