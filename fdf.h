/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:12:27 by dcella-d          #+#    #+#             */
/*   Updated: 2023/02/07 20:33:21 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# ifndef WIDTH_SIZE
# define WIDTH_SIZE 800
# endif

# ifndef HEIGHT_SIZE
# define HEIGHT_SIZE 400
#endif

# include "mlx.h"
# include "libft/libft.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_dir {
	int	x;
	int	y;
}				t_dir;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int	create_trgb(int t, int r, int g, int b);
int	get_b(int trgb);
int	get_g(int trgb);
int	get_r(int trgb);
int	get_t(int trgb);
int	close_win(int keycode, t_vars *vars);
void	my_mlx_line_put(t_data *data, t_dir start, t_dir end, int color);
unsigned int	find_line_x(t_dir start, t_dir end);
unsigned int	find_line_y(t_dir start, t_dir end);


#endif