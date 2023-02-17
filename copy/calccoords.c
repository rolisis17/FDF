/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calccoords.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:45:11 by dcella-d          #+#    #+#             */
/*   Updated: 2023/02/17 16:13:51 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	put_coords(t_dotfile **file, t_calc *ca)
{
	t_dotfile	*headx;
	t_dotfile	*heady;
	int			col;
	int			row;
	int			x;
	int			y;

	heady = (*file);
	headx = heady;
	while (heady)
	{
		col = count_list_length(*file) - count_list_length(headx);
		row = count_list_length(*file) - count_list_depth(headx);
		x = ((ca->width / 2) - (count_list_length(*file) / 2)) \
		+ (ca->lx / (count_list_length(*file))) * col;
		y = ((ca->height / 2) - (count_list_length(*file) / 2)) \
		+ (ca->dy / (count_list_length(*file))) * row;
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

void rotatelistmid(t_vars *vars)
{
	t_dotfile		*headx;
	t_dotfile		*heady;
	t_calc			*ca;
	static double	x_rot;
	static double	y_rot;

	heady = vars->file;
	ca = vars->calc;
	headx = heady;
	while (heady)
	{
		x_rot = ((headx->x - ca->cx) * cos(ca->th * ca->dgm) \
		- (headx->y - ca->cy) * sin(ca->th * ca->dgm) + ca->cx);
		y_rot = ((headx->y - ca->cy) * cos(ca->th * ca->dgm) \
		+ (headx->x - ca->cx) * sin(ca->th * ca->dgm) + ca->cy);
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

void rotatelisty(t_vars *vars)
{
	t_dotfile		*headx;
	t_dotfile		*heady;
	t_calc			*ca;
	static double	y_rot;
	static t_dotfile	*file;

	ca = vars->calc;
	put_coords(&file, ca);
	heady = vars->file;
	headx = heady;
	while (heady)
	{
		y_rot = (((headx->y - ca->cy) * cos(ca->th * ca->dgy)) + ca->cy);
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

void rotatelistx(t_vars *vars)
{
	t_dotfile		*headx;
	t_dotfile		*heady;
	double			x_rot;

	heady = vars->file;
	headx = heady;
	while (heady)
	{
		x_rot = (((headx->x - vars->calc->cx) * cos(vars->calc->th * vars->calc->dgx)) + vars->calc->cx);
		headx->x = x_rot;
		if (headx)
			headx = headx->next;
		else
		{
			heady = heady->down;
			headx = heady;
		}
    }
}
