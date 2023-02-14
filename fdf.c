/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:12:17 by dcella-d          #+#    #+#             */
/*   Updated: 2023/02/14 21:05:51 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"
#include <fcntl.h>
#include <stdio.h>

int	main()
{
	t_vars	vars;
	t_data	img;
	// t_dir	start;
	// t_dir	end;
	t_dotfile	*file = NULL;
	int fd = open("42.fdf", O_RDONLY);

	// start.x = WIDTH/2;
	// start.y = HEIGHT/2;
	// end.x = WIDTH/2 - 55;
	// end.y = HEIGHT/2 + 100;
	readdotfile(&file, fd);
	put_coords(&file);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "Hello world!");
	img.img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	// my_mlx_line_put(&img, start, end, 0x009090FF);
	rotatelistmid(&file, 40);
	rotatelisty(&file, 50);
	// rotatelistx(&file, 1);
	// drawmidlines(&img);
	drawfilelines(file, &img);
	// printdotlist(file);
	printf("%d\n", count_list_length(file));
	printf("%d\n", count_list_depth(file));
	// ft_drawcircle(&img, start, findradius(combinetwodots(start, end)), 0x0011FF00);
	// my_mlx_pixel_put(&img, WIDTH/2, HEIGHT/2, 0xFF);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 5, 5);
	mlx_hook(vars.win, 2, 1L<<0, close_win, &vars);
	mlx_hook(vars.win, 17, 1L<<2, close_win2, &vars);
	mlx_loop(vars.mlx);
}

void	choose_rotate(t_dotfile **file, int rotatecode)
{
	if (rotatecode == 40)
		rotatelisty(file, -10);
	else if (rotatecode == 41)
		rotatelisty(file, 10);
	else if (rotatecode == 50)
		rotatelistmid(file, -10);
	else if (rotatecode == 51)
		rotatelistmid(file, 10);
}

int	close_win(int keycode, t_vars *vars)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit (0);
	}
	if (keycode == 65362)
		return (40);
	if (keycode == 65364)
		return (41);
	if (keycode == 65430)
		return (50);
	if (keycode == 65363)
		return (51);
	return (0);
}

int	close_win2(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit (0);
}
