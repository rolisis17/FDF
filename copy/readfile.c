/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:10:04 by dcella-d          #+#    #+#             */
/*   Updated: 2023/02/17 16:19:20 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"
#include <stdio.h>

void	readdotfile(t_dotfile **file, int fd)
{
	char		*line;
	t_dotfile	*new;
	
	new = NULL;
	if (*file)
		free (*file);
	line = get_next_line(fd);
	while (line)
	{
		makedotlist(&new, ft_split(line, 32));
		combinetwolist(file, new);
		line = get_next_line(fd);
		new = NULL;
	}
}

void printdotlist(t_dotfile *file)
{
	t_dotfile	*temp1;
	
	temp1 = file;
	while (temp1)
	{
		printf("%f, ", temp1->x);
		printf("%f. ", temp1->y);
		if (temp1->next)
			temp1 = temp1->next;
		else
		{
			printf("\n");
			file = file->down;
			temp1 = file;
		}
	}
}

void	makedotlist(t_dotfile **lst, char **splited)
{
	int			res;
	// int			col;
	// int			line;
	int			f;

	f = -1;
	// col = 0;
	// line = 0;
	while (splited[++f])
	{
		res = ft_atoi(splited[f]);
		if (*lst)
			find_next_last(*lst)->next = makenode(res);
		else
			(*lst) = makenode(res);
	}
	free (splited);
}

t_dotfile	*makenode(int dot)
{
	t_dotfile *new;

	new = (t_dotfile *)malloc(sizeof(t_dotfile));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->down = NULL;
	new->dot = dot;
	return (new);
}

void	combinetwolist(t_dotfile **lst1, t_dotfile *lst2)
{
	t_dotfile	*temp1;
	
	temp1 = find_down_last(*lst1);
	while (temp1 && lst2)
	{
		temp1->down = lst2;
		temp1 = temp1->next;
		if (lst2->next)
			lst2 = lst2->next;
	}
	if (!(*lst1))
		(*lst1) = lst2;
}
