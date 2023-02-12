/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:30:49 by dcella-d          #+#    #+#             */
/*   Updated: 2023/02/12 14:41:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_drawcircle(t_data *img, t_dir mid, int r, int color)
{
    int x;
	int y;
    int d;
	
	x = 0;
	y = r;
	d = 3 - 2 * r;
    while (y >= x)
	{
        my_mlx_pixel_put(img, mid.x + x, mid.y + y, color);
        my_mlx_pixel_put(img, mid.x + x, mid.y - y, color);
        my_mlx_pixel_put(img, mid.x - x, mid.y + y, color);
        my_mlx_pixel_put(img, mid.x - x, mid.y - y, color);
        my_mlx_pixel_put(img, mid.x + y, mid.y + x, color);
        my_mlx_pixel_put(img, mid.x + y, mid.y - x, color);
        my_mlx_pixel_put(img, mid.x - y, mid.y + x, color);
        my_mlx_pixel_put(img, mid.x - y, mid.y - x, color);
        if (d < 0)
            d = d + 4 * x + 6;
        else
		{
            d = d + 4 * (x - y) + 10;
            y--;
        }
        x++;
    }
}

t_dir	findmidium(t_line line)
{
	t_dir	medium;
	
	medium.x = ((line.x1 + line.x2) / 2);
	medium.y = ((line.y1 + line.y2) / 2);
	return (medium);
}

double	findradius(t_line line)
{
	double	radius = 0;
	if (line.x1)
		;
	// radius = sqrt((line.x2 - line.x1) * (line.x2 - line.x1) \
	// + (line.y2 - line.y1) * (line.y2 - line.y1));
	return (radius);
}

void	drawmidlines(t_data *img)
{
	t_dir	line1;
	t_dir	line2;

	line1.x = WIDTH/2;
	line1.y = 0;
	line2.x = WIDTH/2;
	line2.y = HEIGHT;
	my_mlx_line_put(img, line1, line2, 0x0000FF00);
	line1.x = WIDTH;
	line1.y = HEIGHT/2;
	line2.x = 0;
	line2.y = HEIGHT/2;
	my_mlx_line_put(img, line1, line2, 0x0000FF00);
}

static void	my_mlx_line_put2(t_data *img, t_line line, t_line line2, int color)
{
    int err;
	int	e2;

	err = (line2.x1 > line2.y1 ? line2.x1 : -line2.y1) / 2;
    while (1)
	{
        my_mlx_pixel_put(img, line.x1, line.y1, color);
        if (line.x1 == line.x2 && line.y1 == line.y2)
			break;
        e2 = err;
        if (e2 > -line2.x1)
		{
			err -= line2.y1;
			line.x1 += line2.x2;
		}
        if (e2 < line2.y1)
		{
			err += line2.x1;
			line.y1 += line2.y2;
		}
    }
}

void	drawfilelines(t_dotfile *file, t_data *img, int color)
{
	t_dotfile	*temp;

	temp = file;
	while (temp)
	{
		if (temp->next)
			my_mlx_line_put(img, makeadot(temp->x, temp->y), makeadot(temp->next->x, temp->next->y), color);
		if (temp->down)
			my_mlx_line_put(img, makeadot(temp->x, temp->y), makeadot(temp->down->x, temp->down->y), color);
		if (temp->next)
			temp = temp->next;
		else
		{
			file = file->down;
			temp = file;
		}
	}
}

void	my_mlx_line_put(t_data *img, t_dir start, t_dir end, int color)
{
    t_line	line;
    t_line	line2;

	line.x1 = start.x;
	line.y1 = start.y;
	line.x2 = end.x;
	line.y2 = end.y;
	line2.x1 = abs(line.x2 - line.x1);
	line2.y1 = abs(line.y2 - line.y1);
	line2.x2 = line.x1 < line.x2 ? 1 : -1;
	line2.y2 = line.y1 < line.y2 ? 1 : -1;
	my_mlx_line_put2(img, line, line2, color);
}
