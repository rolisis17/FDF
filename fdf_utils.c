/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:51:12 by dcella-d          #+#    #+#             */
/*   Updated: 2023/02/15 11:22:27 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_line	combinetwodots(t_dir start, t_dir end)
{
	t_line	line;

	line.x1 = start.x;
	line.y1 = start.y;
	line.x2 = end.x;
	line.y2 = end.y;
	return (line);
}

t_dir	makeadot(int x, int y)
{
	t_dir	coords;
	
	coords.x = x;
	coords.y = y;
	return (coords);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x > WIDTH || y < 0 || y > HEIGHT)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}
//-Lmlx_linux -lmlx_Linux -Llibft -lft -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz