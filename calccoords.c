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
#include <stdio.h>

void	put_coords(t_dotfile **file, t_calc ca)
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
		row = count_list_depth(*file) - count_list_depth(headx);
		x = ((ca.width / 2) - (ca.len / 2)) + (ca.len / count_list_length(*file)) * col;
		y = ((ca.height / 2) - (ca.dep / 2)) + (ca.dep / count_list_depth(*file)) * row;
		// printf("%d, %d\n", x, y);
		headx->x = x;
		headx->y = y;
		next_dot_node(&heady, &headx);
	}
}



void rotatelistmid(t_vars *vars)
{
	t_dotfile		*headx;
	t_dotfile		*heady;
	static double	x_rot;
	static double	y_rot;

	heady = vars->file;
	headx = heady;
	while (heady)
	{
		x_rot = ((headx->x - vars->calc.cx) * cos(vars->calc.th * vars->calc.dgm) \
		- (headx->y - vars->calc.cy) * sin(vars->calc.th * vars->calc.dgm) + vars->calc.cx);
		y_rot = ((headx->y - vars->calc.cy) * cos(vars->calc.th * vars->calc.dgm) \
		+ (headx->x - vars->calc.cx) * sin(vars->calc.th * vars->calc.dgm) + vars->calc.cy);
		headx->x = x_rot;
		headx->y = y_rot;
		printf("%f, %f\n", x_rot, y_rot);
		next_dot_node(&heady, &headx);
	}
	printf("%d, ", vars->calc.dgm);
}

void rotatelisty(t_vars *vars)
{
	t_dotfile		*headx;
	t_dotfile		*heady;
	t_calc			ca;
	static double	y_rot;
	static t_dotfile	*file;

	ca = vars->calc;
	put_coords(&file, vars->calc);
	heady = vars->file;
	headx = heady;
	while (heady)
	{
		y_rot = (((headx->y - ca.cy) * cos(ca.th * ca.dgy)) + ca.cy);
		headx->y = y_rot - (ca.size * headx->dot);
		next_dot_node(&heady, &headx);
    }
}

	// headx->y = ((y_rot - ca.cy) - (ca.size * ca.dgy) / (cos(ca.th * headx->dot))) + ca.cy;

void	next_dot_node(t_dotfile **findow, t_dotfile **finex)
{
	if ((*finex)->next)
		*finex = (*finex)->next;
	else
	{
		*findow = (*findow)->down;
		*finex = *findow;
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
		x_rot = (((headx->x - vars->calc.cx) * cos(vars->calc.th * vars->calc.dgx)) + vars->calc.cx);
		headx->x = x_rot;
		next_dot_node(&heady, &headx);
    }
}
