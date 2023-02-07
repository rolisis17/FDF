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
	
	start.x = WIDTH_SIZE/2;
	start.y = HEIGHT_SIZE/2;
	end.x = WIDTH_SIZE/2;
	start.y = HEIGHT_SIZE/2 - 5;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIDTH_SIZE, HEIGHT_SIZE, "Hello world!");
	img.img = mlx_new_image(vars.mlx, WIDTH_SIZE, HEIGHT_SIZE);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	my_mlx_line_put(&img, start, end, 0x00FF0000);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 5, 5);
	mlx_hook(vars.win, 2, 1L<<0, close_win, &vars);
	mlx_loop(vars.mlx);
}
//create_trgb(get_t(0), get_r(2), get_g(5), get_b(5))

// void	do_line(void *mlx, void *mlx_win, void *img, t_dir start, t_dir end)
// {
	
// }

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
	if (start.x - end.x != 0 || end.x - start.x != 0)
		return (start.x - end.x || end.x - start.x);
	return (start.x);
}

unsigned int	find_line_y(t_dir start, t_dir end)
{
	if (start.y < end.y || end.y < start.y)
		return (start.y|| end.y);
	return (start.y);

}
