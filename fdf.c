/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:12:17 by dcella-d          #+#    #+#             */
/*   Updated: 2023/02/17 20:38:07 by dcella-d         ###   ########.fr       */
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
	int fd = open("42.fdf", O_RDONLY);

	vars = (t_vars *)malloc (sizeof(t_vars));
	if (!vars)
		return (0);
	put_calcs(&vars->calc);
	readdotfile(&file, fd);
	put_coords(&file, vars->calc);
	printf("%d, %d\n", vars->calc.width, vars->calc.height);
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, vars->calc.width, vars->calc.height, "Hello world!");
	img.img = mlx_new_image(vars->mlx, vars->calc.width, vars->calc.height);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_length, &img.endian);
	vars->file = file;
	vars->img = &img;
	// drawfilelines(vars, 1);
	// mlx_put_image_to_window(vars->mlx, vars->win, img.img, 5, 5);
	print_loop(vars);
	// rotatelistmid(vars, -60);
	// rotatelisty(vars, 120);

	print_loop(vars);
	mlx_hook(vars->win, 2, 1L<<0, close_win, vars);
	mlx_hook(vars->win, 17, 1L<<2, close_win2, vars);
	mlx_loop(vars->mlx);
}

void	put_calcs(t_calc *calc)
{
	calc->width = 1080;
	calc->height = 720;
	calc->ratio = 40;
	calc->size = 3;
	calc->th = (M_PI / 180);
	calc->cx = (calc->width / 2);
	calc->cy = (calc->height / 2);
	calc->len = ((calc->width / 100) * calc->ratio);
	calc->dep = ((calc->height / 100) * calc->ratio);
	calc->dgm = 0;
	calc->dgy = 0;
	calc->dgx = 0;
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
	if (keycode == 100)
		vars->calc.dgy++;
	else if (keycode == 97)
		vars->calc.dgy--;
	else if (keycode == 119)
		vars->calc.dgm++;
	else if (keycode == 115)
		vars->calc.dgm--;
	else if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit (0);
	}
	// printf("%d, ", vars->calc.dgy);
	// printf("%d\n", vars->calc.dgm);
	rotate_all(vars);
	print_loop(vars);
	return (1);
}

void	rotate_all(t_vars *vars)
{
	put_coords(&vars->file, vars->calc);
	rotatelistmid(vars);
	rotatelisty(vars);
	rotatelistx(vars);
}

void print_loop(t_vars *vars)
{
	// printdotlist((*vars->file));
	// printf("\n");
	// printf("\n");
	ft_bzero(vars->img->addr, sizeof(vars->img->bpp) * WIDTH * HEIGHT);
	drawfilelines(vars, 1);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 5, 5);
}


int	close_win2(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit (0);
}
