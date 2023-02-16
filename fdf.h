/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:12:27 by dcella-d          #+#    #+#             */
/*   Updated: 2023/02/15 17:03:13 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H


# include "mlx.h"
# include "libft/libft.h"
# include <stdio.h>
# include <math.h>

# define WIDTH 1080
# define HEIGHT 720
# define RATIO 60
# define SIZE 5
# define THETA (M_PI / 180)
# define CENTERX (WIDTH / 2)
# define CENTERY (HEIGHT / 2)
# define LENGTHX ((WIDTH / 100) * RATIO)
# define DEPTHY ((HEIGHT / 100) * RATIO)
# define EIXOX1 (CENTERX - ((LENGTHX) / 2))
# define EIXOX2 (CENTERX + ((LENGTHX) / 2))
# define EIXOY1 (CENTERY - ((DEPTHY) / 2))
# define EIXOY2 (CENTERY + ((DEPTHY) / 2))

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_dir {
	int	x;
	int	y;
}				t_dir;

typedef struct	s_line {
	int		x1;
	int		y1;
	int		size;
	int		x2;
	int		y2;
	double	radius;
}				t_line;

typedef struct	s_dotfile {
	int					dot;
	int					col;
	int					line;
	double				x;
	double				y;
	struct s_dotfile	*next;
	struct s_dotfile	*down;
}				t_dotfile;

typedef struct	s_vars {
	void		*mlx;
	void		*win;
	t_dotfile	*file;
	t_data		*img;
}				t_vars;

void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int			create_trgb(int t, int r, int g, int b);
int			get_b(int trgb);
int			get_g(int trgb);
int			get_r(int trgb);
int			get_t(int trgb);
int			close_win(int keycode, t_vars *vars);
int			close_win2(t_vars *vars);
void		my_mlx_line_put(t_data *data, t_dir start, t_dir end, int size1, int size2);
void		my_mlx_line_put2(t_data *img, t_line line, t_line line2);
void		ft_drawcircle(t_data *img, t_dir mid, int r, int color);
void		drawmidlines(t_data *img);
t_dir		findmidium(t_line line);
double		findradius(t_line line);
t_dir		makeadot(int x, int y);
t_line		combinetwodots(t_dir start, t_dir end);
int			count_list_length(t_dotfile	*lst);
int			count_list_depth(t_dotfile	*lst);
t_dotfile	*find_next_last(t_dotfile	*lst);
t_dotfile	*find_down_last(t_dotfile	*lst);
t_dotfile	*makenode(int dot);
void		readdotfile(t_dotfile **file, int fd);
void		makedotlist(t_dotfile **file, char **splited);
void		combinetwolist(t_dotfile **lst1, t_dotfile *lst2);
void		put_coords(t_dotfile **file);
void		rotatelistmid(t_vars *vars, int degrees);
void		drawfilelines(t_vars *vars, int lock);
void		printdotlist(t_dotfile *file);
void		rotatelisty(t_vars *vars, int degrees);
void		rotatelistx(t_vars *vars, int degrees);
void		choose_rotate(t_dotfile **file, int rotatecode);
void		changecolor(t_line *line, t_line *line2, double *cor);
void		findcolor(int size, double *cor);
void		print_loop(t_vars *vars);

#endif