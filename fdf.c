/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:12:17 by dcella-d          #+#    #+#             */
/*   Updated: 2023/02/12 15:02:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"
#include <fcntl.h>

int	main()
{
	// t_vars	vars;
	// t_data	img;
	// t_dir	start;
	// t_dir	end;
	t_dotfile	*file = NULL;
	int fd = open("basictest.fdf", O_RDONLY);

	// start.x = WIDTH/2;
	// start.y = HEIGHT/2;
	// end.x = WIDTH/2 - 55;
	// end.y = HEIGHT/2 + 100;
	readdotfile(&file, fd);
	put_coords(file);
	// vars.mlx = mlx_init();
	// vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "Hello world!");
	// img.img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	// // my_mlx_line_put(&img, start, end, 0x009090FF);
	// // drawmidlines(&img);
	// ft_drawcircle(&img, start, findradius(combinetwodots(start, end)), 0x0011FF00);
	// my_mlx_pixel_put(&img, WIDTH/2, HEIGHT/2, 0xFF);
	// mlx_put_image_to_window(vars.mlx, vars.win, img.img, 5, 5);
	// mlx_hook(vars.win, 2, 1L<<0, close_win, &vars);
	// mlx_hook(vars.win, 17, 1L<<2, close_win, &vars);
	// mlx_loop(vars.mlx);
}

// int	close_win(int keycode, t_vars *vars)
// {
// 	if (keycode == 65307)
// 		mlx_destroy_window(vars->mlx, vars->win);
// 	exit (0);
// }
