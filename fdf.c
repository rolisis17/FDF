/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:12:17 by dcella-d          #+#    #+#             */
/*   Updated: 2023/02/07 20:37:17 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"

int	main()
{
	t_vars	vars;
	t_data	img;
	t_dir	start;
	t_dir	end;

	start.x = WIDTH_SIZE/2 + 14;
	start.y = HEIGHT_SIZE/2 + 10;
	end.x = WIDTH_SIZE/2 - 55;
	end.y = HEIGHT_SIZE/2 + 100;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIDTH_SIZE, HEIGHT_SIZE, "Hello world!");
	img.img = mlx_new_image(vars.mlx, WIDTH_SIZE, HEIGHT_SIZE);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	//drawline(&img, start, end, 0x009090FF);
	drawmidlines(&img);
	ft_drawcircle(&img, 0x0011FF00);
	my_mlx_pixel_put(&img, start.x, start.y, 0x000000FF);
	my_mlx_pixel_put(&img, end.x, end.y, 0x00FF0000);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 5, 5);
	mlx_hook(vars.win, 2, 1L<<0, close_win, &vars);
	mlx_loop(vars.mlx);
}

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

void	ft_drawcircle(t_data *img, int color)
{
	t_dir	dot1;
	t_dir	dot2;
	double	length;

	dot1.x = WIDTH_SIZE/2 - 38;
	dot1.y = HEIGHT_SIZE/2 + 46;
	dot2.x = WIDTH_SIZE/2;
	dot2.y = HEIGHT_SIZE/2;
	length = sqrt((dot2.x - dot1.x) * (dot2.x - dot1.x) \
	+ (dot2.y - dot1.y) * (dot2.y - dot1.y));
	drawline(img, dot1, dot2, 0x0088FF00);
	ft_drawcircle2(img, length, color);
}

void	drawmidlines(t_data *img)
{
	t_dir	line1;
	t_dir	line2;

	line1.x = WIDTH_SIZE/2;
	line1.y = 0;
	line2.x = WIDTH_SIZE/2;
	line2.y = HEIGHT_SIZE;
	drawline(img, line1, line2, 0x0000FF00);
	line1.x = WIDTH_SIZE;
	line1.y = HEIGHT_SIZE/2;
	line2.x = 0;
	line2.y = HEIGHT_SIZE/2;
	drawline(img, line1, line2, 0x0000FF00);
}

static void	drawline2(t_data *img, t_line line, t_line line2, int color)
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

void drawline(t_data *img, t_dir start, t_dir end, int color)
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
	drawline2(img, line, line2, color);
}

int	close_win(int keycode, t_vars *vars)
{
	if (keycode >= 1L<<0)
	mlx_destroy_window(vars->mlx, vars->win);
	exit (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	my_mlx_line_put(t_data *data, t_dir start, t_dir end, int color)
{
	char	*dst;
	int		x;
	int		y;

	x = find_line_x(start, end);
	y = find_line_y(start, end);
	while (x != end.x || y != end.y)
	{
		dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
		*(unsigned int*)dst = color;
		if (x != end.x)
			x++;
		if (y != end.y)
			y++;
	}
}

unsigned int	find_line_x(t_dir start, t_dir end)
{
	if (start.x - end.x <= 0)
		return (start.x);
	else if (end.x - start.x < 0)
		return (end.x);
	return (start.x);
}

unsigned int	find_line_y(t_dir start, t_dir end)
{
	if (start.y - end.y <= 0)
		return (start.y);
	else if (end.y - start.y < 0)
		return (end.y);
	return (start.y);
}
