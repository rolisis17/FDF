/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:12:17 by dcella-d          #+#    #+#             */
/*   Updated: 2023/02/15 17:03:41 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"
#include <fcntl.h>
#include <stdio.h>

int	main()
{
	t_vars	*vars;
	t_data	img;
	// t_dir	start;
	// t_dir	end;
	t_dotfile	*file = NULL;
	int fd = open("pyramide.fdf", O_RDONLY);

	vars = (t_vars *)malloc (sizeof(t_vars));
	readdotfile(&file, fd);
	put_coords(&file);
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, "Hello world!");
	img.img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_length, &img.endian);
	vars->file = file;
	vars->img = &img;
	// drawfilelines(vars, 1);
	// rotatelistmid(vars, 60);
	// rotatelisty(vars, 60);
	// mlx_put_image_to_window(vars->mlx, vars->win, img.img, 5, 5);
	print_loop(vars);
	mlx_hook(vars->win, 2, 1L<<0, close_win, &vars);
	mlx_hook(vars->win, 17, 1L<<2, close_win2, &vars);
	mlx_loop(vars->mlx);
}

// void	choose_rotate(t_dotfile *file, int rotatecode)
// {
// 	if (rotatecode == 40)
// 		rotatelisty(file, -1);
// 	else if (rotatecode == 41)
// 		rotatelisty(file, 1);
// 	else if (rotatecode == 50)
// 		rotatelistmid(file, -1);
// 	else if (rotatecode == 51)
// 		rotatelistmid(file, 1);
// }

int	close_win(int keycode, t_vars *vars)
{
	
	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit (0);
	}
	if (keycode == 100)
		rotatelisty(vars, -1);
	if (keycode == 97)
		rotatelisty(vars, 1);
	if (keycode == 119)
		rotatelistmid(vars, -1);
	if (keycode == 115)
		rotatelistmid(vars, 1);
	print_loop(vars);
	return (0);
}

void print_loop(t_vars *vars)
{
	ft_bzero(vars->img->addr, sizeof(vars->img->bpp) * WIDTH * HEIGHT);
	drawfilelines(vars, 1);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 5, 5);
}


int	close_win2(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit (0);
}
