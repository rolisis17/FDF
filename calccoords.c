/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calccoords.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:45:11 by dcella-d          #+#    #+#             */
/*   Updated: 2023/02/10 20:55:17 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void calccoords(t_dotfile **file)
{
	int	length;
	int	depth;
	int	sizebtwlines;
	int	sizebtwcol;
	int	x;
	int	y;
	t_line	eixox;
	t_line	eixoy;

	length = count_list_length(file);
	depth = count_list_depth(file);
	eixox = 0;
	eixoy = 0;
	sizebtwcol = ((WIDTH / 100) * RATIO / length - 2);
	sizebtwlines = ((HEIGHT / 100) * RATIO / depth - 2);
	x = (WIDTH / 2 - ((WIDTH / 100) * RATIO) / 2) + (sizebtwcol * (*file)->col);
	y = (HEIGHT / 2 + ((HEIGHT / 100) * RATIO) / 2) + (sizebtwlines * (*file)->line);
	eixox.x1 = ((WIDTH / 100) * RATIO) / 2;
	eixox.
	eixoy = ((HEIGHT / 100) * RATIO) / 2;
}

int	sizebtw(int size, int lock)
{
	static int	sizebtwcol;
	static int	sizebtwlines;

	if (lock == 1)
		sizebtwcol = size;
	if (lock == 2)
		sizebtwlines = size;
	if (lock == 3)
		return (sizebtwcol);
	if (lock == 4)
		return (sizebtwlines);
}
