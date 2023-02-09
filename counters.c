/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counters.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 20:34:54 by dcella-d          #+#    #+#             */
/*   Updated: 2023/02/09 20:44:36 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	count_list_length(t_dotfile	*lst)
{
	int	counter;

	counter = 0;
	while (lst)
	{
		counter++;
		lst = lst->next;
	}
}

t_dotfile	*find_next_last(t_dotfile	*lst)
{
	while (lst)
		lst = lst->next;
	return (lst);
}

t_dotfile	*find_down_last(t_dotfile	*lst)
{
	while (lst)
		lst = lst->down;
	return (lst);
}

int	count_list_depth(t_dotfile	*lst)
{
	int	counter;

	counter = 0;
	while (lst)
	{
		counter++;
		lst = lst->down;
	}
	return (counter);
}
