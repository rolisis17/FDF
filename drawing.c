/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:30:49 by dcella-d          #+#    #+#             */
/*   Updated: 2023/02/09 13:51:11 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


static void ft_drawcircle2(t_data *img, int r, int color)
{
    int x;
	int y;
    int d;
	
	x = 0;
	y = r;
	d = 3 - 2 * r;
    while (y >= x)
	{
        my_mlx_pixel_put(img, WIDTH_SIZE / 2 + x, HEIGHT_SIZE / 2 + y, color);
        my_mlx_pixel_put(img, WIDTH_SIZE / 2 + x, HEIGHT_SIZE / 2 - y, color);
        my_mlx_pixel_put(img, WIDTH_SIZE / 2 - x, HEIGHT_SIZE / 2 + y, color);
        my_mlx_pixel_put(img, WIDTH_SIZE / 2 - x, HEIGHT_SIZE / 2 - y, color);
        my_mlx_pixel_put(img, WIDTH_SIZE / 2 + y, HEIGHT_SIZE / 2 + x, color);
        my_mlx_pixel_put(img, WIDTH_SIZE / 2 + y, HEIGHT_SIZE / 2 - x, color);
        my_mlx_pixel_put(img, WIDTH_SIZE / 2 - y, HEIGHT_SIZE / 2 + x, color);
        my_mlx_pixel_put(img, WIDTH_SIZE / 2 - y, HEIGHT_SIZE / 2 - x, color);
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

void	ft_drawcircle(t_data *img, t_line line, int color)
{
	double	length;

	length = sqrt((line.x2 - line.x1) * (line.x2 - line.x1) \
	+ (line.y2 - line.y1) * (line.y2 - line.y1));
	//drawline(img, dot1, dot2, 0x0088FF00);
	ft_drawcircle2(img, length/2, color);
}

void	drawmidlines(t_data *img)
{
	t_dir	line1;
	t_dir	line2;

	line1.x = WIDTH_SIZE/2;
	line1.y = 0;
	line2.x = WIDTH_SIZE/2;
	line2.y = HEIGHT_SIZE;
	my_mlx_line_put(img, line1, line2, 0x0000FF00);
	line1.x = WIDTH_SIZE;
	line1.y = HEIGHT_SIZE/2;
	line2.x = 0;
	line2.y = HEIGHT_SIZE/2;
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
