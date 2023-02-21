/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:30:49 by dcella-d          #+#    #+#             */
/*   Updated: 2023/02/17 20:46:34 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_line_put2(t_vars *vars, t_line line, t_line line2)
{
    int err;
	int	e2;
	double cor;

	err = (line2.x1 > line2.y1 ? line2.x1 : -line2.y1) / 2;
    while (1)
	{
		line2.radius = findradius(line);
		changecolor(&line, &line2, &cor);
        my_mlx_pixel_put(vars, line.x1, line.y1, tcolor(cor));
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

void	my_mlx_line_put(t_vars *vars, t_dir start, t_dir end, int size1, int size2)
{
    t_line	line;
    t_line	line2;

	line.x1 = start.x;
	line.y1 = start.y;
	line.x2 = end.x;
	line.y2 = end.y;
	line.size = size1;
	line2.size = size2;
	line.radius = findradius(line);
	line2.x1 = abs(line.x2 - line.x1);
	line2.y1 = abs(line.y2 - line.y1);
	line2.x2 = find_line2(line.x1, line.x2, 1, -1);
	line2.y2 = find_line2(line.y1, line.y2, 1, -1);
	line2.radius = findradius(line2);
	my_mlx_line_put2(vars, line, line2);
}

void	drawfilelines(t_vars *vars, int lock)
{
	t_dotfile	*temp;
	t_dotfile	*temp2;

	temp = vars->file;
	temp2 = temp;
	while (temp)
	{
		if (temp->next && lock == 1)
			my_mlx_line_put(vars, makeadot(temp->x, temp->y),\
	 makeadot(temp->next->x, temp->next->y), temp->dot, temp->next->dot);
		if (temp->down && lock == 2)
			my_mlx_line_put(vars, makeadot(temp->x, temp->y),\
	 makeadot(temp->down->x, temp->down->y), temp->dot, temp->down->dot);
		next_dot_node(&temp2, &temp);
	}
	if (lock == 1)
		drawfilelines(vars, 2);
}

int	find_line2(int x1, int x2, int yes, int no)
{
	if (x1 < x2)
		return (yes);
	else
		return (no);
}

int	makecorratio(double cor, double cor2)
{
	if (cor > cor2)
		return (cor - cor2);
	if (cor < cor2)
		return (cor2 - cor);
	else
		return (cor);
}
