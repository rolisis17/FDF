/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:12:17 by dcella-d          #+#    #+#             */
/*   Updated: 2023/02/09 21:10:15 by dcella-d         ###   ########.fr       */
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
	my_mlx_line_put(&img, start, end, 0x009090FF);
	drawmidlines(&img);
	ft_drawcircle(&img, combinetwodots(start, end), 0x0011FF00);
	my_mlx_pixel_put(&img, start.x, start.y, 0x000000FF);
	my_mlx_pixel_put(&img, end.x, end.y, 0x00FF0000);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 5, 5);
	mlx_hook(vars.win, 2, 1L<<0, close_win, &vars);
	mlx_hook(vars.win, 17, 1L<<2, close_win, &vars);
	mlx_loop(vars.mlx);
}

int	close_win(int keycode, t_vars *vars)
{
	if (keycode >= 1L<<0)
		mlx_destroy_window(vars->mlx, vars->win);
	exit (0);
}
