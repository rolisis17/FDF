/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:10:04 by dcella-d          #+#    #+#             */
/*   Updated: 2023/02/09 21:10:41 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	readdotfile(t_dotfile **file, int fd)
{
	char		*line;
	t_dotfile	*new;
	
	line = get_next_line(fd);
	while (line)
	{
		makedotlist(&new, ft_split(line, 32));
		combinetwolist(file, &new);
		line = get_next_line(fd);
	}
}


void	makedotlist(t_dotfile **file, char **splited)
{
	t_dotfile	*lst;
	int			res;
	int			f;

	f = -1;
	while (splited[++f])
	{
		res = ft_atoi(splited[f]);
		if (lst)
			find_next_last(lst)->next = makenode(res);
		else
			lst = makenode(res);
	}
}

t_dotfile	*makenode(int dot)
{
	t_dotfile *new;

	new = (t_dotfile *)malloc(sizeof(t_dotfile));
	new->next = NULL;
	new->down = NULL;
	new->dot = dot;
	return (new);
}

void	combinetwolist(t_dotfile **lst1, t_dotfile **lst2)
{
	t_dotfile	*temp1;
	t_dotfile	*temp2;
	
	temp1 = lst1;
	temp2 = lst2;
	if (!lst1)
		lst1 = lst2;
	while (temp1)
	{
		temp1->down = temp2;
		temp1 = temp1->next;
		if (temp2->next)
			temp2 = temp2->next;
	}
}
