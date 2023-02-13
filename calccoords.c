/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calccoords.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:45:11 by dcella-d          #+#    #+#             */
/*   Updated: 2023/02/13 18:31:45 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

// void calccoords(t_dotfile **file)
// {
// 	int	length;
// 	int	depth;
// 	int	sizebtwlines;
// 	int	sizebtwcol;
// 	int	x;
// 	int	y;
// 	t_line	eixox;
// 	t_line	eixoy;

// 	length = count_list_length(file);
// 	depth = count_list_depth(file);
// 	eixox = 0;
// 	eixoy = 0;
// 	sizebtwcol = ((WIDTH / 100) * RATIO / length - 2);
// 	sizebtwlines = ((HEIGHT / 100) * RATIO / depth - 2);
// 	x = (WIDTH / 2 - ((WIDTH / 100) * RATIO) / 2) + (sizebtwcol * (*file)->col);
// 	y = (HEIGHT / 2 + ((HEIGHT / 100) * RATIO) / 2) + (sizebtwlines * (*file)->line);
// 	eixox.x1 = ((WIDTH / 100) * RATIO) / 2;
// 	eixox.
// 	eixoy = ((HEIGHT / 100) * RATIO) / 2;
// }

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

void rotatelistmid(t_dotfile **file, int degrees)
{
	t_dotfile		*headx;
	t_dotfile		*heady;
	static double	x_rot;
	static double	y_rot;

	heady = (*file);
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

void rotatelisty(t_dotfile **file, int degrees)
{
	t_dotfile		*headx;
	t_dotfile		*heady;
	static double	y_rot;

	heady = (*file);
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

void rotatelistx(t_dotfile **file, int degrees)
{
	t_dotfile		*headx;
	t_dotfile		*heady;
	static double	x_rot;

	heady = (*file);
	headx = heady;
	while (heady)
	{
		x_rot = (CENTERX / 2 - headx->x ) * cos(THETA * degrees) + CENTERX - (SIZE *headx->dot);
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

// void drawCircle(int xc, int yc, int x, int y, int color, int graphicDevice, double theta, int clockwise, struct point *points, int *n)
// {
//     int x_rot, y_rot;
//     if (clockwise)
//     {
//         x_rot = xc + (x * cos(theta) + y * sin(theta));
//         y_rot = yc + (y * cos(theta) - x * sin(theta));
//     }
//     else
//     {
//         x_rot = xc + (x * cos(theta) - y * sin(theta));
//         y_rot = yc + (y * cos(theta) + x * sin(theta));
//     }
//     points[*n].x = x_rot;
//     points[*n].y = y_rot;
//     *n += 1;
//     points[*n].x = 2 * xc - x_rot;
//     points[*n].y = y_rot;
//     *n += 1;
//     points[*n].x = x_rot;
//     points[*n].y = 2 * yc - y_rot;
//     *n += 1;
//     points[*n].x = 2 * xc - x_rot;
//     points[*n].y = 2 * yc - y_rot;
//     *n += 1;
// }

// void midpointCircle(int xc, int yc, int r, int color, int graphicDevice, double theta, int clockwise, struct point *points, int *n)
// {
//     int x = 0, y = r;
//     int d = 1 - r;
//     drawCircle(xc, yc, x, y, color, graphicDevice, theta, clockwise, points, n);
//     while (y > x)
//     {
//         if (d < 0)
//         {
//             d += 2 * x + 3;
//             x++;
//         }
//         else
//         {
//             d += 2 * (x - y) + 5;
//             x++;
//             y--;
//         }
//         drawCircle(xc, yc, x, y, color, graphicDevice, theta, clockwise, points, n);
//     }
// }

// void drawCircle(t_data *img, int xc, int yc, int x, int y, int color)
// {
//     int	x_rot;
// 	int	y_rot;
//     if (WAY)
//     {
//         x_rot = xc + (x * cos(THETA) + y * sin(THETA));
//         y_rot = yc + (y * cos(THETA) - x * sin(THETA));
//     }
//     else
//     {
//         x_rot = xc + (x * cos(THETA) - y * sin(THETA));
//         y_rot = yc + (y * cos(THETA) + x * sin(THETA));
//     }
//     putpixel(x_rot, y_rot, color);
//     putpixel(2 * xc - x_rot, y_rot, color);
//     putpixel(x_rot, 2 * yc - y_rot, color);
//     putpixel(2 * xc - x_rot, 2 * yc - y_rot, color);
// }

// void midpointCircle(int xc, int yc, int r, int color, int graphicDevice, double theta, int clockwise)
// {
//     int x = 0, y = r;
//     int d = 1 - r;
//     drawCircle(xc, yc, x, y, color, graphicDevice, theta, clockwise);
//     while (y > x)
//     {
//         if (d < 0)
//         {
//             d += 2 * x + 3;
//             x++;
//         }
//         else
//         {
//             d += 2 * (x - y) + 5;
//             x++;
//             y--;
//         }
//         drawCircle(xc, yc, x, y, color, graphicDevice, theta, clockwise);
//     }
// }

// int	sizebtw(int size, int lock)
// {
// 	static int	sizebtwcol;
// 	static int	sizebtwlines;

// 	if (lock == 1)
// 		sizebtwcol = size;
// 	if (lock == 2)
// 		sizebtwlines = size;
// 	if (lock == 3)
// 		return (sizebtwcol);
// 	if (lock == 4)
// 		return (sizebtwlines);
// }
