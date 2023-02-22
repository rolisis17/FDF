/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findcolor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:51:45 by dcella-d          #+#    #+#             */
/*   Updated: 2023/02/22 18:18:10 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	tcolor2(int *r, int *g, int *b)
{
	if ((*b) < 0)
	{
		(*r) = (*b) * -1;
		(*b) = 0;
	}
	if ((*r) > 255)
	{
		(*g) = (*g) - ((*r) - 255);
		(*r) = 255;
	}
	if ((*g) < 0)
	{
		(*b) = (*g) * -1;
		(*g) = 0;
	}
}

int	tcolor(double colour)
{
	int	r;
	int	b;
	int	g;

	r = 0;
	g = 0;
	b = 0;
	if (colour < 255)
	{
		g = colour;
		b = 255;
	}
	if (colour > 255)
	{
		b = b - (colour - 255);
		g = 255;
	}
	tcolor2(&r, &g, &b);
	return (create_trgb(0, r, g, b));
}

double	changecolor(t_line *line, t_line *line2)
{
	double	size;
	double	corratio;
	double	cor;

	cor = line->cor;
	corratio = (makecorratio(line->cor, line2->cor) / line->radius);
	size = line->radius - line2->radius;
	if (line->radius != line2->radius && line->cor != line2->cor)
	{
		if (line->cor > line2->cor)
			cor -= corratio * size;
		if (line2->cor < line->cor)
			cor += corratio * size;
	}
	return (cor);
}

double	findcolor(int size)
{
	double	corratio;
	int		cor;

	if (size == checkdot(0, 1))
		cor = 0;
	corratio = (1020 / ((checkdot(0, 0) * 2) + 1));
	cor = corratio * (size + checkdot(0, 0));
	return (cor);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
