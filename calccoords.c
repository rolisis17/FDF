/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calccoords.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:45:11 by dcella-d          #+#    #+#             */
/*   Updated: 2023/02/15 17:03:08 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void put_coords(t_dotfile **file)
{
	t_dotfile	*headx;
	t_dotfile	*heady;
	int			length;
	int			depth;
	int			totalcol;
	int			totalrow;
	int			col;
	int			row;
	double			x;
	double			y;

	heady = (*file);
	headx = heady;
	length = (WIDTH / 100) * RATIO;
	depth = (HEIGHT / 100) * RATIO;
	totalcol = count_list_length(*file);
	totalrow = count_list_depth(*file);
	while (heady)
	{
		col = totalcol - count_list_length(headx);
		row = totalrow - count_list_depth(headx);
		x = ((WIDTH / 2) - (length / 2)) + (length / (totalcol)) * col;
		y = ((HEIGHT / 2) - (depth / 2)) + (depth / (totalrow)) * row;
		headx->x = x;
		headx->y = y;
		if (headx->next)
			headx = headx->next;
		else
		{
			heady = heady->down;
			headx = heady;
		}
	}
}

void rotatelistmid(t_vars *vars, int degrees)
{
	t_dotfile		*headx;
	t_dotfile		*heady;
	static double	x_rot;
	static double	y_rot;

	heady = vars->file;
	headx = heady;
	while (heady)
	{
		x_rot = ((headx->x - CENTERX) * cos(THETA * degrees) - (headx->y - CENTERY) * sin(THETA * degrees) + CENTERX);
		y_rot = ((headx->y - CENTERY) * cos(THETA * degrees) + (headx->x - CENTERX) * sin(THETA * degrees) + CENTERY);
		headx->x = x_rot;
		headx->y = y_rot;
		if (headx)
			headx = headx->next;
		if (!(headx))
		{
			heady = heady->down;
			headx = heady;
		}
	}
}

void rotatelisty(t_vars *vars, int degrees)
{
	t_dotfile		*headx;
	t_dotfile		*heady;
	static double	y_rot;

	heady = vars->file;
	headx = heady;
	while (heady)
	{
		y_rot = ((headx->y - CENTERY) * cos(THETA * degrees) + CENTERY - (SIZE * headx->dot));
		headx->y = y_rot;
		if (headx)
			headx = headx->next;
		if (!(headx))
		{
			heady = heady->down;
			headx = heady;
		}
    }
}

void rotatelistx(t_vars *vars, int degrees)
{
	t_dotfile		*headx;
	t_dotfile		*heady;
	double	x_rot;

	heady = vars->file;
	headx = heady;
	while (heady)
	{
		x_rot = (headx->x - CENTERX);
		x_rot = x_rot * cos(THETA * degrees);
		x_rot = x_rot + CENTERX - (SIZE * headx->dot);
		printf("%f", x_rot);
		// headx->x = x_rot;
		if (headx && degrees)
			headx = headx->next;
		else
		{
			heady = heady->down;
			headx = heady;
		}
    }
}
