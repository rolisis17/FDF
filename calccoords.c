/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calccoords.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:45:11 by dcella-d          #+#    #+#             */
/*   Updated: 2023/02/17 20:39:24 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_coords(t_dotfile **file, t_calc ca)
{
	t_dotfile	*headx;
	t_dotfile	*heady;
	int			col;
	int			row;
	static int	x;
	static int	y;

	heady = (*file);
	headx = heady;
	while (heady)
	{
		col = count_list_length(*file) - count_list_length(headx);
		row = count_list_depth(*file) - count_list_depth(headx);
		x = ((ca.cx) - ((ca.width / 100) * ca.ratio) / 2) + (((ca.width / 100)\
		 * ca.ratio) / count_list_length(*file)) * col;
		y = ((ca.cy) - (((ca.height / 100) * ca.ratio) / 2)) + (((ca.height /\
		 100) * ca.ratio) / count_list_depth(*file)) * row;
		headx->x = x;
		headx->y = y;
		next_dot_node(&heady, &headx);
	}
}

void	put_calcs(t_calc *calc)
{
	calc->width = 1080;
	calc->height = 720;
	calc->ratio = 40;
	calc->size = 3;
	calc->th = (M_PI / 180);
	calc->cx = (calc->width / 2);
	calc->cy = (calc->height / 2);
	calc->len = ((calc->width / 100) * calc->ratio);
	calc->dep = ((calc->height / 100) * calc->ratio);
	calc->dgm = 0;
	calc->dgy = 0;
	calc->dgx = 0;
}


int	checkdot(int dot, int ck)
{
	static int	max;
	static int	min;
	int			sign;

	sign = 1;
	if (dot < min)
		min = dot;
	if (dot > max)
		max = dot;
	if (min < 0)
		sign = -1;
	if ((min * sign) > max)
		max = (min * sign);
	if ((min * sign) < max)
		min = max * -1;
	if (ck)
		return (min);
	return (max);
}

void	next_dot_node(t_dotfile **findow, t_dotfile **finex)
{
	if ((*finex)->next)
		(*finex) = (*finex)->next;
	else
	{
		if ((*findow)->down)
			(*findow) = (*findow)->down;
		else
			(*findow) = NULL;
		(*finex) = (*findow);
	}
}
